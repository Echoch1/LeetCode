#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        map<int, int> hash;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            hash[arr[i]] = i;
        }
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 2; i < n; ++i) {
            for (int j = i - 1; j >= 1 && arr[j] * 2 > arr[i]; --j) {
                if (hash.find(arr[i] - arr[j]) != hash.end()) {
                    dp[j][i] = max(dp[hash[arr[i] - arr[j]]][j] + 1, 3);
                }
                res = max(res, dp[j][i]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 4, 7, 8, 9, 10, 14, 15, 18, 23, 32, 50};
    int res = s.lenLongestFibSubseq(nums);
    cout << res << endl;
}