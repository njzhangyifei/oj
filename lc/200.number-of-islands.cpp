class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }


        int res = 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        vector<pair<int, int>> dirs = {
            {0, 1},
            {0,-1},
            {1, 0},
            {-1,0}
        };

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }

                if (visited[i][j]) {
                    continue;
                }

                pair<int, int> start = make_pair(i, j);

                std::queue<pair<int, int>> q;
                visited[i][j] = true;
                q.push(start);

                res += 1;
                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();

                    for (int d = 0; d < dirs.size(); ++d) {
                        auto next_dir = dirs[d];
                        pair<int, int> next = make_pair(curr.first + next_dir.first, curr.second + next_dir.second);

                        if (next.first < 0 || next.first >= grid.size() || 
                            next.second < 0 || next.second >= grid[0].size()){
                            continue;
                        }

                        if (grid[next.first][next.second] == '1' && !visited[next.first][next.second]) { 
                            visited[next.first][next.second] = true;
                            q.push(next);
                        }
                    }
                }
            }
        }

        return res;

    }
};
