#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> stack1;
        for (int i = 0; i < height.size(); i++) {
            while (!stack1.empty() && height[i] >= height[stack1.top()]) {
                int h = height[stack1.top()];
                stack1.pop();
                if (!stack1.empty()) {
                    res += (i - stack1.top() - 1) * (min(height[i], height[stack1.top()]) - h);
                }
            }
            stack1.push(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums = { 5, 4, 5 };
    cout << s.trap(nums) << endl;
}