#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int res = 0;
        stack<int> stack1;
        for (int i = 0; i < nums.size(); i++) {
            if (stack1.empty() || nums[i] < nums[stack1.top()]) {
                stack1.push(i);
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stack1.empty() && nums[i] >= nums[stack1.top()]) {
                res = max(res, i - stack1.top());
                stack1.pop();
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums = { 6, 1, 0, 2, 2 };
    cout << s.maxWidthRamp(nums) << endl;
}