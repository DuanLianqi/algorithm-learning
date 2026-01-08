#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void removeZeroes(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0; fast != nums.size(); fast++) {
            if(nums[fast] != 0) {
                swap(nums[fast], nums[slow]);
                slow++;
            }
        }
    }
};

int main() {
    vector<int> vec;
    int num;
    while(cin >> num) {
        vec.push_back(num);
        if(cin.get() == '\n')
            break;
    }
    Solution obj;
    obj.removeZeroes(vec);
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return 0;
}