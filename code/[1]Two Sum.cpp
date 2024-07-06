#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                return { hash[target - nums[i]], i };
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = { 2, 7, 11, 5 };
    int target = 9;
    vector<int> res = s.twoSum(nums, target);
    for (const auto &n : res) {
        cout << n << endl;
    }
}