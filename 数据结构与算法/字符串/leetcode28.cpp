#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz1 = haystack.size(), sz2 = needle.size();
        for(int i = 0; i + sz2 < sz1; i++) {
            bool flag = true;
            for(int j = 0; j < sz2; j++) {
                if(haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                return i;
            }
        }
        return -1;
    }
};
