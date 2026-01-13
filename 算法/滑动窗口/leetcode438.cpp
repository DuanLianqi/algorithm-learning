#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret, sCount(26, 0), pCount(26, 0);
        int sLen = s.size(), pLen = p.size();

        if(sLen < pLen) {
            return ret;
        }
        for(int i = 0; i < pLen; i++) {
            pCount[p[i] - 'a']++;
        }

        int left = 0;
        for(int right = 0; right < sLen; right++) {
            sCount[s[right] - 'a']++;

            if(right - left + 1 == pLen) {
                if(sCount == pCount) {
                    ret.push_back(left);
                }
                sCount[s[left] - 'a']--;
                left++;
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
