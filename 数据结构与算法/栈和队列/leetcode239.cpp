#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size();
        priority_queue<pair<int, int>> q;
        vector<int> ret;
        for(int i = 0; i < k; i++) {
            q.push({nums[i], i});
        }
        ret.push_back(q.top().first);
        for(int i = k; i < sz; i++) {
            q.push({nums[i], i});
            while(q.top().second <= i - k) {
                q.pop();
            }
            ret.push_back(q.top().first);
        }
        return ret;
    }
};
