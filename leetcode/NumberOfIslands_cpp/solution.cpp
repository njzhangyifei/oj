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
        int numIslands(vector<vector<char>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            std::unordered_map<
                pair<int, int>, 
                vector<pair<int, int>>
            > map;
            for (int i = 0; i < row-1; ++i) {
                for (int j = 0; j < col-1; ++j) {
                    if (grid[i][j]) {
                    }
                }
            }
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // Solution s;
    // s.numIslands()
    return 0;
}

