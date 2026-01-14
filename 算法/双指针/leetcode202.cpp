#include <iostream>

using namespace std;

class Solution {
public:
    int getNext(int n) {
        int sum = 0;
        while(n) {
            int temp = n % 10;
            sum += temp * temp;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slowRunner = n, fastRunner = getNext(n);

        while(fastRunner != 1 && slowRunner != fastRunner) {
            slowRunner = getNext(slowRunner);
            fastRunner = getNext(getNext(fastRunner));
        }

        return fastRunner == 1;
    }
};

int main() {
    int n;
    cin >> n;
    cout << boolalpha << Solution().isHappy(n) << endl;
    return 0;
}
