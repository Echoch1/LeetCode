#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dpX(m, 0);
        vector<int> dpY(m, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int countX = 0;
            int countY = 0;
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'X') {
                    dpX[j]++;
                } else if (grid[i][j] == 'Y') {
                    dpY[j]++;
                }
                countX += dpX[j];
                countY += dpY[j];
                if ((countX == countY) && countX) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {{'X', 'Y', '.'}, {'Y', '.', '.'}};
    int res = s.numberOfSubmatrices(grid);
    cout << res << endl;
}