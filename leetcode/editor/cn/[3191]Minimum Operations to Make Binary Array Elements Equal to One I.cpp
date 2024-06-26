#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i + 2 < nums.size(); i++) {
            if (!nums[i]) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                res++;
            }
        }
        return ((!nums[nums.size() - 2]) || (!nums[nums.size() - 1])) ? -1 :res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}