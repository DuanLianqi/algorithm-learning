#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int num = 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1, sum = n * n;
        while(num <= sum) {
            for(int i = left; i <= right; i++) {
                ret[top][i] = num++;
            }
            top++;
            for(int i = top; i <= bottom; i++) {
                ret[i][right] = num++;
            }
            right--;
            for(int i = right; i >= left; i--) {
                ret[bottom][i] = num++;
            }
            bottom--;
            for(int i = bottom; i >= top; i--) {
                ret[i][left] = num++;
            }
            left++;
        }
        return ret;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ret = Solution().generateMatrix(n);
    for(auto& row : ret) {
        for(auto& index : row) {
            cout << index << "\t";
        }
        cout << endl;
    }
    return 0;
}
