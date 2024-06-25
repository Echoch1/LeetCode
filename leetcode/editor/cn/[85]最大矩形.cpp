#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
        int res = 0;
        stack<int> stack1;
        for (int i = matrix.size() - 1; i >= 0; i--) {
            while(!stack1.empty()) {
                stack1.pop();
            }
            stack1.push(0);
            dp[i].insert(dp[i].begin(), 0);
            dp[i].push_back(0);
            for (int j = 0; j < dp[i].size(); j++) {
                while (!stack1.empty() && dp[i][j] < dp[i][stack1.top()]) {
                    int h = dp[i][stack1.top()];
                    stack1.pop();
                    if (!stack1.empty()) {
                        res = max(res, h * (j - stack1.top() - 1));
                    }
                }
                stack1.push(j);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<vector<char>> nums = { { '1', '0', '1', '0', '0' },
                                  { '1', '0', '1', '1', '1' },
                                  { '1', '1', '1', '1', '1' },
                                  { '1', '0', '0', '1', '0' } };
    cout << s.maximalRectangle(nums) << endl;
}