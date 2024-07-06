#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        long long res = 0;
        stack<int> stack1;
        vector<long long> pre;
        vector<long long> suf;
        long long sum = 0;
        pre.push_back(0);
        suf.push_back(0);
        stack1.push(heights.size());
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (stack1.size() > 1 && heights[i] <= heights[stack1.top()]) {
                int cur = stack1.top();
                stack1.pop();
                sum -= static_cast<long long>(heights[cur]) * (stack1.top() - cur);
            }
            sum += static_cast<long long>(heights[i]) * (stack1.top() - i);
            suf.push_back(sum);
            stack1.push(i);
        }
        while(!stack1.empty()) {
            stack1.pop();
        }
        stack1.push(-1);
        sum = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (stack1.size() > 1 && heights[i] <= heights[stack1.top()]) {
                int cur = stack1.top();
                stack1.pop();
                sum -= static_cast<long long>(heights[cur]) * (cur - stack1.top());
            }
            sum += static_cast<long long>(heights[i]) * (i - stack1.top());
            pre.push_back(sum);
            stack1.push(i);
        }
        for (int i = 0; i < pre.size(); i++) {
            res = max(res, pre[i] + suf[suf.size() - 1 - i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 3, 2, 5, 5, 2, 3 };
    cout << s.maximumSumOfHeights(nums) << endl;
}