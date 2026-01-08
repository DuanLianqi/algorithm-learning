#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchLeft(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, res = n;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(target <= nums[mid]) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }

    int searchRight(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, res = n;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(target >= nums[mid]) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int leftBounder = searchLeft(nums, target);
        if(leftBounder < 0 || leftBounder >= n) {
            return {-1, -1};
        }
        if(nums[leftBounder] != target) {
            return {-1, -1};
        }
        int rightBounder = searchRight(nums, target);
        return {leftBounder, rightBounder};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 9, 9, 11};
    int target1 = 3, target2 = 5, target3 = 6, target4 = 9, target5 = 11, target6 = 13;
    Solution obj;
    cout << "the start pos and end pos of target1 is : " << (obj.searchRange(nums, target1))[0] << ", " << (obj.searchRange(nums, target1))[1] << endl;
    cout << "the start pos and end pos of target2 is : " << (obj.searchRange(nums, target2))[0] << ", " << (obj.searchRange(nums, target2))[1] << endl;
    cout << "the start pos and end pos of target3 is : " << (obj.searchRange(nums, target3))[0] << ", " << (obj.searchRange(nums, target3))[1] << endl;
    cout << "the start pos and end pos of target4 is : " << (obj.searchRange(nums, target4))[0] << ", " << (obj.searchRange(nums, target4))[1] << endl;
    cout << "the start pos and end pos of target5 is : " << (obj.searchRange(nums, target5))[0] << ", " << (obj.searchRange(nums, target5))[1] << endl;
    cout << "the start pos and end pos of target6 is : " << (obj.searchRange(nums, target6))[0] << ", " << (obj.searchRange(nums, target6))[1] << endl;
    return 0;
}