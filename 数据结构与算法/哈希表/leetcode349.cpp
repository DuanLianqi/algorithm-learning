#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset, ret;
        for(auto num : nums1) {
            uset.insert(num);
        }
        for(auto num : nums2) {
            if(uset.contains(num)) {
                ret.insert(num);
            }
        }
        vector<int> res;
        for(auto i : ret) {
            res.push_back(i);
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ret = Solution().intersection(nums1, nums2);
    for(auto i : ret) {
        cout << i << " ";
    }
    return 0;
}
