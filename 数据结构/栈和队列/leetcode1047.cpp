#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for(auto c : s) {
            if(!stk.empty() && stk.back() == c) {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
            
        }
        return stk;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().removeDuplicates(s) << endl;
    return 0;
}
