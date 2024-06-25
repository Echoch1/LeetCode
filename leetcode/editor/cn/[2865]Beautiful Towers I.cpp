#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        long long res = 0;
        stack<int> stack1;
        vector<long long> pre;
        vector<long long> suf;
        long long sum = 0;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!stack1.empty() && heights[i] <= heights[stack1.top()]) {
                stack1.pop();
                sum -= heights[stack1.top()] * (heights.size() - stack1.top());
            }
            stack1.push(i);
            sum += heights[i] * (heights.size() - i);
            suf.push_back(sum);
        }
        while(!stack1.empty()) {
            stack1.pop();
        }
        sum = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!stack1.empty() && heights[i] <= heights[stack1.top()]) {
                stack1.pop();
                sum -= heights[stack1.top()] * (heights.size() - stack1.top());
            }
            stack1.push(i);
            sum += heights[i] * (heights.size() - i);
            pre.push_back(sum);
        }
        for (int i = 0; i < pre.size(); i++) {
            res = max(res, pre[i] + suf[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}