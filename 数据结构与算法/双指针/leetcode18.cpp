#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int sz = nums.size();
        for(int i = 0; i < sz - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            long long need = target - nums[i];
            for(int j = i + 1; j < sz - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                long long need2 = need - nums[j];
                int left = j + 1, right = sz - 1;
                while(left < right) {
                    if(nums[left] + nums[right] < need2) {
                        left++;
                    } else if(nums[left] + nums[right] > need2) {
                        right--;
                    } else {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while(left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> ret = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> vec = Solution().fourSum(ret, target);
    for(auto& v : vec) {
        cout << "[";
        for(auto num : v) {
            cout << num << ",";
        }
        cout << "]";
    }
    return 0;
}
