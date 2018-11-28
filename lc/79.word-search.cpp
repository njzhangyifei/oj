class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (check(board, used, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<pair<int, int>> dirs = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1},
    };

    bool check(vector<vector<char>> & board, 
                vector<vector<bool>> & used,
    string & word, int x, int y, int str_i) {
        if (board[x][y] != word[str_i]) {
            return false;
        }
        if (str_i == word.size()-1) {
            return true;
        } else if (str_i >= word.size()) {
            return false;
        }
        used[x][y] = true;
        for (int i = 0; i < dirs.size(); ++i) {
            auto d = dirs[i];
            int n_x = x + d.first;
            int n_y = y + d.second;
            if (n_x < 0 || n_x >= board.size() ||
                n_y < 0 || n_y >= board[0].size()) {
                continue;
            }
            if (used[n_x][n_y]) {
                continue;
            }
            if (check(board,used, word, n_x, n_y, str_i+1)) {
                return true;
            };
        }
        used[x][y] = false;
        return false;
    }
};
