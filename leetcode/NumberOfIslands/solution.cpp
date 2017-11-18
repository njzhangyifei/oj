#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        std::vector<pair<int, int>> dirs = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };

        void explore(
                vector<vector<char>> & grid,
                int x, int y,
                int row, int col
                ) {
            grid[x][y] = 'x';
            for (int i = 0; i < dirs.size(); ++i) {
                int xx = x + dirs[i].first;
                int yy = y + dirs[i].second;
                if ((xx >= 0 && xx < row) && (yy >= 0 && yy < col)) {
                    if (grid[xx][yy] == '1') {
                        explore(grid, xx, yy, row, col);
                    }
                }
            }

        }
        int numIslands(vector<vector<char>>& grid) {
            int row = grid.size();
            if (row == 0) {
                return 0;
            }
            int col = grid[0].size();
            int count = 0;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (grid[i][j] == '1') {
                        explore(grid, i, j, row, col);
                        count ++;
                    }
                }
            }
            return  count;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

