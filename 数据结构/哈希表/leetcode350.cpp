#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap1, umap2;
        vector<int> ret;
        for(auto num : nums1) {
            umap1[num]++;
        }
        for(auto num : nums2) {
            umap2[num]++;
        }

        for(auto num : umap2) {
            int number = num.first;
            if(umap1.contains(number)) {
                if(umap1[number] < umap2[number]) {
                    for(int i = 0; i < umap1[number]; i++) {
                        ret.push_back(number);
                    }
                } else {
                    for(int i = 0; i < umap2[number]; i++) {
                        ret.push_back(number);
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ret = Solution().intersect(nums1, nums2);
    for(auto i : ret) {
        cout << i << " ";
    }
    return 0;
}