#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, res = n;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(target <= nums[mid]) {
                right = mid - 1;
                res = mid;
            } else if(target > nums[mid]) {
                left = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 7, 9};
    int target1 = -2, target2 = 3, target3 = 6, target4 = 11;
    Solution obj;
    cout << "the insert index of target1 in nums is : " << obj.searchInsert(nums, target1) << endl;
    cout << "the insert index of target2 in nums is : " << obj.searchInsert(nums, target2) << endl;
    cout << "the insert index of target3 in nums is : " << obj.searchInsert(nums, target3) << endl;
    cout << "the insert index of target4 in nums is : " << obj.searchInsert(nums, target4) << endl;
    return 0;
}