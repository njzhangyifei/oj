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
        int shortestDistance(vector<vector<int>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            std::vector<vector<bool>> valid (row, vector<bool>(col, true));
            std::vector<vector<int>>  val (row, vector<int>(col, 0));
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (grid[i][j] == 1) {
                        // possible start
                        vector<vector<bool>> visited (row, vector<bool>(col, false));
                        for (int ii = 0; ii < row; ++ii) {
                            for (int jj = 0; jj < col; ++jj) {
                                if (visited[ii][jj] == false) {
                                    valid[ii][jj] = false;
                                }
                            }
                        }
                        bfs(val, grid, visited, make_pair(i,j));
                    }
                }
            }

            int minimum = INT_MAX;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (valid[i][j]) {
                        minimum = min(val[i][j], minimum);
                    }
                }
            }

            return (minimum == INT_MAX) ? -1 : minimum;
        }


        std::vector<pair<int, int>> dirs = {
            {0, -1},
            {0, 1},
            {-1, 0},
            {1, 0}
        };

        void bfs(
                vector<vector<int>> & value, 
                vector<vector<int>> & grid,
                vector<vector<bool>> & visited,
                pair<int, int> start
                ){
            std::queue<pair<int, int>> to_visit;
            visited[start.first][start.second] = true;
            to_visit.push(start);
            
            int inqueue = 1;
            int distance = 0;
            while (to_visit.size()) {
                auto curr = to_visit.front();
                to_visit.pop();
                value[curr.first][curr.second]  += distance;
                for (int i = 0; i < dirs.size(); ++i) {
                    int xx = curr.first +  dirs[i].first;
                    int yy = curr.second + dirs[i].second;
                    if ( (xx < 0 || xx >= value.size() ) ||
                         (yy < 0 || yy >= value[0].size())) {
                        continue;
                    }
                    if (grid[xx][yy] != 0 || visited[xx][yy]) {
                        continue;
                    }
                    // not visited
                    visited[xx][yy] = true;
                    to_visit.push(make_pair(xx,yy));
                }
                inqueue--;
                if (inqueue == 0) {
                    // one level done
                    inqueue = to_visit.size();
                    distance ++;
                }
            }
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

