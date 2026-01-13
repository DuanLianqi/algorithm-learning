#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int sLen = s.size(), pLen = p.size();

        if(sLen < pLen) {
            return ret;
        }

        vector<int> sCount(26, 0), pCount(26, 0);
        for(int i = 0; i < pLen; i++) {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }

        if(sCount == pCount) {
            ret.push_back(0);
        }

        for(int i = 0; i < sLen - pLen; i++) {
            sCount[s[i] - 'a']--;
            sCount[s[i + pLen] - 'a']++;

            if(sCount == pCount) {
                ret.push_back(i + 1);
            }
        }

        return ret;
    }
};

int main() {
    string s, p;
    cin >> s >> p;
    vector<int> ret;
    ret = Solution().findAnagrams(s, p);
    for(auto& i : ret) {
        cout << i << " ";
    }
    return 0;
}
