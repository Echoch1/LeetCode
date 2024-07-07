#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
        vector<vector<int>> dpx(x + 1, vector<int>(y + 1, 0));
        vector<vector<int>> dpy(x + 1, vector<int>(y + 1, 0));
        for (int i = 0; i < grid.size(); ++i) {
            dpx[i + 1][1] = dpx[i][1];
            dpy[i + 1][1] = dpy[i][1];
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 'X') {
                    dpx[i + 1][j + 1] = dpx[i + 1][j] + 1;
                } else if (grid[i][j] == 'Y') {
                    dpy[i + 1][j + 1] = dpy[i + 1][j] + 1;
                }
                if ((dpx[i + 1][j + 1] == dpy[i + 1][j + 1]) && dpx[i + 1][j + 1]) {
                    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] + 1;
                }
            }
        }
        return dp[x][y];
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {{'X', 'Y', '.'}, {'Y', '.', '.'}};
    int res = s.numberOfSubmatrices(grid);
    cout << res << endl;
}