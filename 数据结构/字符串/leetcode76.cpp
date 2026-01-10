#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> umapS, umapT;
        int less = 0;
        for(auto& c : t) {
            if(umapT[c] == 0) {
                less++;
            }
            umapT[c]++;
        }

        int m = s.size(), ansLeft = -1, ansRight = m;
        int left = 0;
        for(int right = 0; right < m; right++) {
            char temp = s[right];
            umapS[temp]++;
            if(umapS[temp] == umapT[temp]) {
                less--;
            }
            while(less == 0) {
                if(right - left < ansRight - ansLeft) {
                    ansLeft = left;
                    ansRight = right;
                }

                char x = s[left];
                if(umapS[x] == umapT[x]) {
                    less++;
                }
                umapS[x]--;
                left++;
            }
        }
        return ansLeft < 0 ? "" : s.substr(ansLeft, ansRight - ansLeft + 1);
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    cout << Solution().minWindow(s, t) << endl;
    return 0;
}
