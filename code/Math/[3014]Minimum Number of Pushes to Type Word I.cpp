#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        return (4 * (word.size() / 8) + word.size() % 8) * (word.size() / 8 + 1);
    }
};