#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap1;
        for(auto num1 : nums1) {
            for(auto num2 : nums2) {
                umap1[num1 + num2]++;
            }
        }

        int res = 0;
        for(auto num3 : nums3) {
            for(auto num4 : nums4) {
                int sum = 0 - num3 - num4;
                res += umap1[sum];
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};
    cout << Solution().fourSumCount(nums1, nums2, nums3, nums4);
    return 0;
}
