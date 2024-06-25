#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct Car {
        int position = 0;
        int speed = 0;
    };

    static bool cmp(const Car &a, const Car &b) {
        return a.position < b.position;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for (int i = 0; i < position.size(); i++) {
            Car car;
            car.position = position[i];
            car.speed = speed[i];
            cars.push_back(car);
        }
        sort(cars.begin(), cars.end(), cmp);
        vector<float> time;
        for (const auto &car : cars) {
            time.push_back((target - car.position) / static_cast<float>(car.speed));
        }
        stack<int> stack1;
        for (int i = 0; i < time.size(); i++) {
            while (!stack1.empty() && time[i] >= time[stack1.top()]) {
                stack1.pop();
            }
            stack1.push(i);
        }
        return stack1.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> a = { 6, 8 };
    vector<int> b = { 3, 2 };
    cout << s.carFleet(10, a, b) << endl;
}