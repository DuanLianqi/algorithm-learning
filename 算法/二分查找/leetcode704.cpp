#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(target > nums[mid]) {
                left = mid + 1;
            } else if(target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 7, 9};
    int target1 = -2, target2 = 3, target3 = 6, target4 = 11;
    Solution obj;
    cout << "the index of target1 in nums is : " << obj.search(nums, target1) << endl;
    cout << "the index of target2 in nums is : " << obj.search(nums, target2) << endl;
    cout << "the index of target3 in nums is : " << obj.search(nums, target3) << endl;
    cout << "the index of target4 in nums is : " << obj.search(nums, target4) << endl;
    return 0;
}
