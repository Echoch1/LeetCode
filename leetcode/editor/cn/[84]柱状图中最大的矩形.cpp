#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> stack1;
        stack1.push(0);
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        for (int i = 0; i < heights.size(); i++) {
            while(!stack1.empty() && heights[i] < heights[stack1.top()]) {
                int h = heights[stack1.top()];
                stack1.pop();
                if (!stack1.empty()) {
                    res = max(res, h * (i - stack1.top() - 1));
                }
            }
            stack1.push(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> nums = { 5, 4 ,5 };
    cout << s.largestRectangleArea(nums) << endl;
}