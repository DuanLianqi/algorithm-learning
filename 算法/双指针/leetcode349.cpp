#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sz1 = nums1.size(), sz2 = nums2.size();
        vector<int> ret;
        int index1 = 0, index2 = 0;
        while(index1 < sz1 && index2 < sz2) {
            int num1 = nums1[index1], num2 = nums2[index2];
            if(num1 == num2) {
                if(ret.empty() || num1 != ret.back()) {
                    ret.push_back(num1);
                }
                index1++;
                index2++;
            } else if(num1 > num2) {
                index2++;
            } else {
                index1++;
            }
        }
        return ret;
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
