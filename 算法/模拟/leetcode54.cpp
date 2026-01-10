#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret;
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        int num = 1;
        while(num <= m * n) {
            for(int i = left; i <= right && num <= m * n; i++) {
                ret.push_back(matrix[top][i]);
                num++;
            }
            top++;
            for(int i = top; i <= bottom && num <= m * n; i++) {
                ret.push_back(matrix[i][right]);
                num++;
            }
            right--;
            for(int i = right; i >= left && num <= m * n; i--) {
                ret.push_back(matrix[bottom][i]);
                num++;
            }
            bottom--;
            for(int i = bottom; i >= top && num <= m * n; i--) {
                ret.push_back(matrix[i][left]);
                num++;
            }
            left++;
        }
        return ret;
    }
};

int main() {
    int n;
    vector<vector<int>> maxtrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> maxtrix2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ret1 = Solution().spiralOrder(maxtrix1);
    for(auto& row : ret1) {
        cout << row << " ";
    }
    cout << endl;
    vector<int> ret2 = Solution().spiralOrder(maxtrix2);
    for(auto& row : ret2) {
        cout << row << " ";
    }
    cout << endl;
    return 0;
}
