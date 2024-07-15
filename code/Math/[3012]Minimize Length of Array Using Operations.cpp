#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int m = ranges::min(nums);
        for (int num : nums) {
            if (num % m) {
                return 1;
            }
        }
        return (count(nums.begin(), nums.end(), m) + 1) / 2;
    }
};