#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElemet(vector<int>& nums, int val) {
        int slow = 0;
        for(int fast = 0; fast != nums.size(); fast++) {
            if(nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

int main() {
    vector<int> vec;
    int num, val;
    while(cin >> num) {
        vec.push_back(num);
        if(cin.get() == '\n')
            break;
    }
    cin >> val;
    Solution obj;
    int sz = obj.removeElemet(vec, val);
    for(int i = 0; i < sz; i++) {
        cout << vec[i] << " ";
    }
    return 0;
}