#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, n = nums.size(), sum = 0;
        int ret = n + 1;
        for(int right = 0; right < n; right++) {
            sum += nums[right];
            while(sum >= target) {
                ret = min(ret, right - left + 1);
                sum -= nums[left++];
            }
        }
        return ret == n + 1 ? 0 : ret;
    }
};

int main() {
    vector<int> ret = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << Solution().minSubArrayLen(target, ret) << endl;
    return 0;
}
