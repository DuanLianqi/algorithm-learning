#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> uset = {"+", "-", "*", "/"};
        for(auto& token : tokens) {
            if(uset.find(token) == uset.end()) {
                stk.push(stoi(token));
            } else {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();
                if(token == "+") {
                    stk.push(second + first);
                } else if(token == "-") {
                    stk.push(second - first);
                } else if(token == "*") {
                    stk.push(second * first);
                } else {
                    stk.push(second / first);
                }
            }
        }
        return stk.top();
    }
};
