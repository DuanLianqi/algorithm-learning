#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ret;
        int sz1 = nums1.size(), sz2 = nums2.size();
        int index1 = 0, index2 = 0;
        while(index1 < sz1 && index2 < sz2) {
            int number1 = nums1[index1], number2 = nums2[index2];
            if(number1 == number2) {
                ret.push_back(number1);
                index1++;
                index2++;
            } else if(number1 < number2) {
                index1++;
            } else {
                index2++;
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