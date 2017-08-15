#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <stack>
#include <memory>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int dfs(vector<vector<int>> & matrix, int ** longest,
                int _i, int _j, int num_row, int num_col){
            int val = matrix[_i][_j];
            int max_len = 1;
            if (_i > 0 && matrix[_i-1][_j] > val) {
                // up
                int len = 0;
                if (longest[_i-1][_j] >= 0) {
                    len = longest[_i-1][_j]; 
                } else {
                    len = dfs(matrix, longest, _i-1, _j, num_row, num_col);
                }
                max_len = max(len + 1, max_len);
            }
            if (_i < num_row-1 && matrix[_i+1][_j] > val) {
                // down
                int len = 0;
                if (longest[_i+1][_j] >=  0) {
                    len = longest[_i+1][_j]; 
                } else {
                    len = dfs(matrix, longest, _i+1, _j, num_row, num_col);
                }
                max_len = max(len + 1, max_len);
            }
            if (_j > 0 && matrix[_i][_j-1] > val) {
                // left
                int len = 0;
                if (longest[_i][_j-1] >= 0) {
                    len = longest[_i][_j-1];
                } else {
                    len = dfs(matrix, longest, _i, _j-1, num_row, num_col);
                }
                max_len = max(len + 1, max_len);
            }
            if (_j < num_col-1 && matrix[_i][_j+1] > val) {
                // right
                int len = 0;
                if (longest[_i][_j+1] >= 0) {
                    len = longest[_i][_j+1];
                } else {
                    len = dfs(matrix, longest, _i, _j+1, num_row, num_col);
                }
                max_len = max(len + 1, max_len);
            }
            longest[_i][_j] = max_len;
            return max_len;
        }
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            int num_row = matrix.size();
            if (num_row == 0) {
                return 0;
            }
            int num_col = matrix[0].size();
            if (num_col == 0) {
                return 0;
            }

            int * longest[num_row];
            for (int i = 0; i < num_row; ++i) {
                longest[i] = new int[num_col];
                for (int j = 0; j < num_col; ++j) {
                    longest[i][j]=-1;
                }
            }

            int max_res = 0;
            for (int i = 0; i < num_row; ++i) {
                for (int j = 0; j < num_col; ++j) {
                    int res = 0;
                    if (longest[i][j] >= 0) {
                        res = longest[i][j];
                        max_res = max(max_res, res);
                        continue;
                    }

                    // cerr << "dfs on " << i  << ", " << j << endl;
                    int r = dfs(matrix, (int **)longest, i, j, num_row, num_col);
                    // cerr << "result = " << r << endl;
                    longest[i][j] = r;
                    max_res = max(r, max_res);
                }
            }
            return max_res;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<int>> input = 
    // {
        // {3,4,5},
        // {3,2,6},
        // {2,2,1}
    // };

    // {
  // {9,9,4},
  // {6,6,8},
  // {2,1,1}
// };
{
    {10, 10, 10},
    {10, 10, 10}
};
    Solution s;
    auto ans = s.longestIncreasingPath(input);

    cerr << ans << endl;

    return 0;
}

