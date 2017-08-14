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
        struct node {
            int row;
            int col;
            int val;

            bool special;
            
            node (int r, int c, bool s=false){
                row = r;
                col = c;
                special = s;
            }
        };

        vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
            int num_row = matrix.size();
            if (num_row == 0) {
                return vector<pair<int, int>>();
            }
            int num_col = matrix[0].size();
            if (num_col == 0) {
                return vector<pair<int, int>>();
            }
            node * map[num_row][num_col];
            for (int i = 0; i < num_row; ++i) {
                for (int j = 0; j < num_col; ++j) {
                    map[i][j] = new node(i, j);
                    map[i][j]->val = matrix[i][j];
                }
            }

            node * pacific = new node(-1, -1, true);
            node * atlantic = new node(num_row, num_col, true);
            std::map<node *, vector<node *>> adj;
            for (int i = 0; i < num_row; ++i) {
                for (int j = 0; j < num_col; ++j) {
                    node * current = map[i][j];
                    if (i == 0 || j == 0) {
                        adj[pacific].push_back(current);
                    }
                    if (i == num_row-1 || j == num_col-1) {
                        adj[atlantic].push_back(current);
                    }
                    // up
                    if (i > 0 && map[i-1][j]->val >= current->val) {
                        adj[current].push_back(map[i-1][j]);
                    }
                    // down
                    if (i < num_row-1 && map[i+1][j]->val >= current->val) {
                        adj[current].push_back(map[i+1][j]);
                    }

                    // left
                    if (j > 0 && map[i][j-1]->val >= current->val) {
                        adj[current].push_back(map[i][j-1]);
                    }
                    // down
                    if (j < num_col-1 && map[i][j+1]->val >= current->val) {
                        adj[current].push_back(map[i][j+1]);
                    }
                }
            }

            std::unordered_map<node *, bool> visited;

            std::queue<node *> q;
            q.push(pacific);
            while (q.size()) {
                node * current = q.front();
                q.pop();
                for (auto i : adj[current]) {
                    if (!visited[i]) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }

            vector<pair<int, int>> ans;

            std::unordered_map<node *, bool> atlantic_visit;
            q.push(atlantic);
            while (q.size()) {
                node * current = q.front();
                if (visited[current]) {
                    // visited
                    ans.push_back(make_pair(current->row, current->col));
                }
                q.pop();
                for (auto i : adj[current]) {
                    if (!atlantic_visit[i]) {
                        q.push(i);
                        atlantic_visit[i] = true;
                    }
                }
            }

            sort(ans.begin(), ans.end());

            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

