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
        vector<pair<int,int>> dirs = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1}
        };

        void dfs(
                vector<vector<int>> & matrix,
                vector<vector<int>> & val,
                int num_row, int num_col,
                int x, int y
                ) {

            for (int i = 0; i < dirs.size(); ++i) {
                int xx = dirs[i].first + x;
                int yy = dirs[i].second + y;
                // check each
                val[x][y] = max(val[x][y], 1);
                if ((xx >= 0 && xx < num_row) && (yy >= 0 && yy < num_col)) {
                    if (matrix[xx][yy] > matrix[x][y]) {
                        // increasing!
                        if (val[xx][yy] == -1) {
                            // visit
                            dfs(matrix, val, num_row, num_col, xx, yy);
                        }
                        val[x][y] = max(val[x][y], 1+val[xx][yy]);
                    }
                }
            }
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
            vector<vector<int>> val (num_row, vector<int>(num_col, -1));
            int max_res = INT_MIN;
            for (int i = 0; i < num_row; ++i) {
                for (int j = 0; j < num_col; ++j) {
                    if (val[i][j] == -1) {
                        dfs(matrix, val, num_row, num_col, i, j);
                    }
                    max_res = max(max_res, val[i][j]);
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

