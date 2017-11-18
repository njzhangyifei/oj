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
        int maxKilledEnemies(vector<vector<char>>& grid) {
            int num_row = grid.size();
            if (num_row == 0) {
                return 0;
            }
            int num_col = grid[0].size();

            std::vector<pair<int,int>> pos_dir = {
                {-1, 0},
                {0, -1},
                {1, 0},
                {0, 1},
            };

            vector<vector<vector<int>>> v (
                4,
                vector<vector<int>>(num_row,
                    vector<int>(num_col, 0)));

            for (int d = 0; d < pos_dir.size(); ++d) {
                auto dir = pos_dir[d];
                if (d < 2) {
                    for (int i = 0; i < num_row; ++i) {
                        for (int j = 0; j < num_col; ++j) {
                            int xx = i + dir.first;
                            int yy = j + dir.second;
                            int val = 0;
                            if (((xx >= 0) && (xx < num_row)) &&
                                ((yy >= 0) && (yy < num_col))) {
                                val = v[d][xx][yy];
                            }
                            if (grid[i][j] == 'E') {
                                val ++;
                            } else if (grid[i][j] == 'W') {
                                val = 0;
                            }
                            v[d][i][j] = val;
                        }
                    }
                } else {
                    for (int i = num_row-1; i >= 0; i--) {
                        for (int j = num_col-1; j >= 0; j--) {
                            int xx = i + dir.first;
                            int yy = j + dir.second;
                            int val = 0;
                            if (((xx >= 0) && (xx < num_row)) &&
                                ((yy >= 0) && (yy < num_col))) {
                                val = v[d][xx][yy];
                            }
                            if (grid[i][j] == 'E') {
                                val ++;
                            } else if (grid[i][j] == 'W') {
                                val = 0;
                            }
                            v[d][i][j] = val;
                        }
                    }
                }
            }

            int max_bomb = 0;
            for (int i = 0; i < num_row; ++i) {
                for (int j = 0; j < num_col; ++j) {
                    if (grid[i][j] != '0') {
                        continue;
                    }
                    int curr = 0;
                    for (int k = 0; k < pos_dir.size(); ++k) { 
                        auto dir = pos_dir[k];
                        int xx = i + dir.first;
                        int yy = j + dir.second;
                        int val = 0;
                        if (((xx >= 0) && (xx < num_row)) &&
                            ((yy >= 0) && (yy < num_col))) {
                            val = v[k][xx][yy];
                        }
                        curr += val;
                    }
                    max_bomb = max(curr, max_bomb);
                }
            }

            return max_bomb;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

