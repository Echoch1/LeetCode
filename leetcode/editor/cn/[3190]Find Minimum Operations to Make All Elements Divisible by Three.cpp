#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (const auto & num : nums) {
            res += (num % 3 != 0);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums = { 3, 4, 6 };
    cout << s.minimumOperations(nums) << endl;
}