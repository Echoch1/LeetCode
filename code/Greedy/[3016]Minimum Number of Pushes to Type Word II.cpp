#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int res = 0;
        int count[30];
        memset(count, 0, sizeof(count));
        for (char c : word) {
            count[c - 'a']++;
        }
        sort(count, count + 26, greater<int>());
        for (int i = 0; i < 26; i++) {
            res += count[i] * (i / 8 + 1);
        }
        return res;
    }
};