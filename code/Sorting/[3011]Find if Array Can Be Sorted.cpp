#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int pre_max = 0;
        for (int i = 0; i < nums.size();) {
            int tmp_max = 0;
            int bits = __builtin_popcount(nums[i]);
            while (i < nums.size() && __builtin_popcount(nums[i]) == bits) {
                if (nums[i] < pre_max) {
                    return false;
                }
                tmp_max = max(tmp_max, nums[i]);
                i++;
            }
            pre_max = tmp_max;
        }
        return true;
    }
};