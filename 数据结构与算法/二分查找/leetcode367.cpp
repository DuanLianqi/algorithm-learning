#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while(left <= right) {
            long long mid = (right - left) / 2 + left;
            long long temp = mid * mid;
            if(temp < num) {
                left = mid + 1;
            } else if(temp > num){
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int val;
    std::cin >> val;
    std::cout << std::boolalpha << Solution().isPerfectSquare(val) << std::endl;
    return 0;
}