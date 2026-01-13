#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int tArray[26] = {0};
        for(auto& c : s) {
            tArray[c - 'a']++;
        }
        for(auto& c : t) {
            tArray[c - 'a']--;
        }
        for(auto& i : tArray) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    cout << boolalpha << Solution().isAnagram(s, t) << endl;
    return 0;
}
