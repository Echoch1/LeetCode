#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string str = s;
        for (int i = 0; i < s.size(); i++) {
            str[i] = s[(i + k) % s.size()];
        }
        return str;
    }
};

int main() {
    Solution s;
    string str = "byd";
    string res = s.getEncryptedString(str, 4);
    cout << res << endl;
}