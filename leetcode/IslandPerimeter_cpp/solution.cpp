#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
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
        int num_row;
        int num_col;
        int perimeter(vector<vector<int>> & grid, int i, int j){
            int perimeter = 0;
            if (i == 0) {
                perimeter += 1;
            }
            if (i == num_row-1) {
                perimeter += 1;
            }
            if (j == 0) {
                perimeter += 1;
            }
            if (j == num_col-1) {
                perimeter += 1;
            }
            if (i > 0 && grid[i-1][j] == 0) {
                perimeter += 1;
            }
            if (i < num_row-1 && grid[i+1][j] == 0) {
                perimeter += 1;
            }
            if (j > 0 && grid[i][j-1] == 0) {
                perimeter += 1;
            }
            if (i < num_row-1 && grid[i][j+1] == 0) {
                perimeter += 1;
            }
            return perimeter;
        }

        int islandPerimeter(vector<vector<int>>& grid) {
            num_row = grid.size();
            if (num_row == 0) {
                return 0;
            }
            int perim = 0;
            num_col = grid[0].size();
            for (int i = 0; i < num_row; ++i) {
                for (int j = 0; j < num_col; ++j) {
                    if (grid[i][j]==1) {
                        perim += perimeter(grid, i, j);
                    }
                }
            }
            return perim;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

