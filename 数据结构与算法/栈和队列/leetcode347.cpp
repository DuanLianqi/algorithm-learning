#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto& num : nums) {
            umap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> p(cmp);
        for(auto& u : umap) {
            p.push(u);
            if(p.size() > k) {
                p.pop();
            }
        }

        vector<int> ret;
        for(int i = 0; i < k; i++) {
            ret.push_back(p.top().first);
            p.pop();
        }

        return ret;
    }
};

int main() {
    vector<int> nums = {0,2,0,2,7,2,3,3,3,2};
    int k = 2;

    vector<int> ret = Solution().topKFrequent(nums, k);
    for(auto i : ret) {
        cout << i << " ";
    }
    return 0;
}
