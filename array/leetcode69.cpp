#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, res = x;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(static_cast<long long>(mid * mid) <= x) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};

int main() {
    int val;
    std::cin >> val;
    std::cout << Solution().mySqrt(val) << std::endl;
    return 0;
}