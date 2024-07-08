#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        int m = (1 << n) - 1;
        for (int i = 0; i <= m; ++i) {
            int j = i ^ m;
            if ((j & (j >> 1)) == 0) {
                bitset<18> bs(i);
                res.push_back(bs.to_string().substr(18 - n));
            }
        }
        return res;
    }
};

int main() {
    // Solution s;
}