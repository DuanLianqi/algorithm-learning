#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        for(int fast = slow + 1; fast != nums.size(); fast++) {
            if(nums[fast] != nums[slow]) {
                swap(nums[fast], nums[++slow]);
            }
        }
        return slow + 1;
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
    int sz = obj.removeDuplicates(vec);
    for(int i = 0; i < sz; i++) {
        cout << vec[i] << " ";
    }
    return 0;
}
