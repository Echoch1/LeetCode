#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                n += !nums[i];
                continue;
            }
            if (nums[i - 1] && !nums[i]) {
                n++;
            }
        }
        return (nums[nums.size() - 1]) ? 2 * n : 2 * n - 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}