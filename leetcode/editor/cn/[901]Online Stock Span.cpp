#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        prices_.push_back(price);
        while (!stackPrice_.empty() && prices_[prices_.size() - 1] >= prices_[stackPrice_.top()]) {
            stackPrice_.pop();
        }
        int res = stackPrice_.empty() ? prices_.size() : (prices_.size() - 1 - stackPrice_.top());
        stackPrice_.push(prices_.size() - 1);
        return res;
    }

private:
    stack<int> stackPrice_;
    vector<int> prices_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    StockSpanner s;
    cout << s.next(100) << endl;
    cout << s.next(101) << endl;
}