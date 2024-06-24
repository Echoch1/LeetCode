#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> stack1;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack1.empty() && temperatures[i] > temperatures[stack1.top()]) {
                res[stack1.top()] = i - stack1.top();
                stack1.pop();
            }
            stack1.push(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> nums = { 30, 60, 90 };
    vector<int> res = s.dailyTemperatures(nums);
    for (const int &n : res) {
        cout << n;
    }
    cout << endl;
}