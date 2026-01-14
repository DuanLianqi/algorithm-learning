#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = umap.find(target - nums[i]);
            if(iter != umap.end()) {
                return {iter->second,  i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ret = Solution().twoSum(nums, target);
    for(auto i : ret) {
        cout << i << " ";
    }
    return 0;
}
