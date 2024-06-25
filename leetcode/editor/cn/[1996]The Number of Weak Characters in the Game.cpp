#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        stack<int> stack1;
        int res = 0;
        for (int i = 0; i < properties.size(); i++) {
            while (!stack1.empty() && properties[i][1] > properties[stack1.top()][1]) {
                stack1.pop();
                res++;
            }
            stack1.push(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}