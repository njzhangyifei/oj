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

        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };

        bool explore(
                vector<vector<char>> & board,
                std::set<pair<int, int>> & visited,
                string & word, 
                int i, int j,
                int row_num, int col_num,
                int cur){
            for (auto d : directions) {
                auto _i = i + d.first;
                auto _j = j + d.second;
                if (_i >= 0 && _i < row_num && _j >= 0 && _j < col_num) {
                    // cerr << "visiting" << _i << "," << _j << endl;
                    if (board[_i][_j] != word[cur]) {
                        continue;
                    }
                    if (visited.find(make_pair(_i, _j)) != visited.end()) {
                        // skip in path
                        continue;
                    }
                    if (cur == word.size()-1) {
                        return true;
                    }
                    visited.insert(make_pair(_i, _j));
                    bool b =  explore(board, visited, word, _i, _j, row_num, col_num, cur+1);
                    if (b) {
                        return true;
                    }
                    visited.erase(make_pair(_i, _j));
                }
            }
            return false;
        }

        bool exist(vector<vector<char>>& board, string word) {
            if (word.size() == 0) {
                return true;
            }
            int num_row = board.size();
            if (num_row == 0) {
                return false;
            }
            int num_col = board[0].size();
            if (num_col == 0) {
                return false;
            }
            for (int i = 0; i < num_row; ++i) {
                for (int j = 0; j < num_col; ++j) {
                    if (board[i][j] == word[0]) {
                        std::set<pair<int,int>> visited;
                        visited.insert(make_pair(i,j));
                        if (word.size() == 1) {
                            return true;
                        }
                        bool b = explore(board, visited, word, i, j, num_row, num_col, 1);
                        if (b) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<vector<char>> map = {{'a','a'}};
    string dict = "aaa";
    Solution s;
    s.exist(map, dict);

    return 0;
}

