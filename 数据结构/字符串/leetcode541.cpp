#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverse(string& s, int left, int right) {
        while(left < right) {
            swap(s[left++], s[right--]);
        }
    }

    string reverseStr(string s, int k) {
        int sz = s.size();
        for(int i = 0; i < sz; i += 2 * k) {
            if(i + k > sz) {
                reverse(s, i, sz - 1);
            } else {
                reverse(s, i, i + k - 1);
            }
        }
        return s;
    }
};

int main() {
    string s = "abcdefg";
    int k;
    cin >> k;
    cout << Solution().reverseStr(s, k) << endl;
    return 0;
}
