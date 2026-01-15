#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m[26] = {0};
        for(char c : magazine) {
            m[c - 'a']++;
        }

        for(char c : ransomNote) {
            m[c - 'a']--;
            if(m[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    string ransomNote, magazine;
    cin >> ransomNote >> magazine;
    cout << boolalpha << Solution().canConstruct(ransomNote, magazine) << endl;
    return 0;
}
