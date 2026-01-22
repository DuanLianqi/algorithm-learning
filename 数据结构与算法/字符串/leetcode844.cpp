#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string buildString(string& s) {
        string ret;
        for(auto& c : s) {
            if(c == '#') {
                if(!ret.empty()) {
                    ret.pop_back();
                }
            } else {
                ret.push_back(c);
            }
        }
        return ret;
    }

    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }
};

int main() {
    string s = "ab##", t = "c#d#";
    cout << boolalpha << Solution().backspaceCompare(s, t) << endl;
    return 0;
}