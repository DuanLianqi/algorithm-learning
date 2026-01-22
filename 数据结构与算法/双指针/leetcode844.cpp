#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int skipS = 0, skipT = 0;

        while(i >= 0 || j >= 0) {
            while(i >= 0) {
                if(s[i] == '#') {
                    skipS++;
                    i--;
                } else if(skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }

            while(j >= 0) {
                if(t[j] == '#') {
                    skipT++;
                    j--;
                } else if(skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }

            if(i >= 0 && j >= 0) {
                if(s[i] != t[j]) {
                    return false;
                }
            } else {
                if(i >= 0 || j >= 0) {
                    return false;
                }
            }

            i--;
            j--;
        }
        return true;
    }
};

int main() {
    string s1 = "ab##", t1= "c#d#";
    cout << boolalpha << Solution().backspaceCompare(s1, t1) << endl;
    string s2 = "ab#c", t2= "ad#c";
    cout << boolalpha << Solution().backspaceCompare(s2, t2) << endl;
    string s3 = "a#c", t3= "b";
    cout << boolalpha << Solution().backspaceCompare(s3, t3) << endl;
    return 0;
}