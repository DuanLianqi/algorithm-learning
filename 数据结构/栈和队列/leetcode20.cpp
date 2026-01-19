#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> umap = {
            {']', '['},
            {')', '('},
            {'}', '{'}
        };
        stack<char> stk;
        for(auto c : s) {
            if(!stk.empty() && umap[c] == stk.top()) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};

int main() {
    string s;
    cin >> s;
    cout << boolalpha << Solution().isValid(s) << endl;
    return 0;
}
