#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(auto& str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = umap.begin(); it != umap.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
