#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> umap;
        int left = 0, n = fruits.size();
        int ret = 0;
        for(int right = 0; right < n; right++) {
            umap[fruits[right]]++;
            while(umap.size() > 2) {
                int out = fruits[left];
                umap[out]--;
                if(umap[out] == 0) {
                    umap.erase(out);
                }
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

int main() {
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout << Solution().totalFruit(fruits) << endl;
    return 0;
}
