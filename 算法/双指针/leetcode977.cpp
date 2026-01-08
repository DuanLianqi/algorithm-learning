#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        int left = 0, right = n - 1, index = n - 1;
        while(left <= right) {
            int leftTemp = nums[left] * nums[left];
            int rightTemp = nums[right] * nums[right];
            if(leftTemp <= rightTemp) {
                ret[index] = rightTemp;
                right--;
            } else {
                ret[index] = leftTemp;
                left++;
            }
            index--;
        }
        return ret;
    }
};

int main() {
    vector<int> vec1 = {-4, -1, 0, 3, 10};
    vector<int> vec2 = {-7, -3, 2, 3, 11};
    vector<int> ret1 = Solution().sortedSquares(vec1);
    vector<int> ret2 = Solution().sortedSquares(vec2);
    for(auto& i : ret1) {
        cout << i << " ";
    }
    cout << endl;
    for(auto& i : ret2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
