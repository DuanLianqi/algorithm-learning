#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int temp = 0 - nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if(nums[left] + nums[right] == temp) {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if(nums[left] + nums[right] < temp) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> ret = {-1,0,1,2,-1,-4};
    vector<vector<int>> vec = Solution().threeSum(ret);
    for(auto& v : vec) {
        cout << "[";
        for(auto num : v) {
            cout << num << ",";
        }
        cout << "]";
    }
    return 0;
}
