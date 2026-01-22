#include <iostream>
#include <unordered_set>

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
        unordered_set<int> uset;

        while(n != 1) {
            if(uset.contains(n)) {
                return false;
            }
            uset.insert(n);
            n = getNext(n);
        }

        return true;
    }
};

int main() {
    int n;
    cin >> n;
    cout << boolalpha << Solution().isHappy(n) << endl;
    return 0;
}
