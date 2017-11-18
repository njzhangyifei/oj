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
        int solve(
                vector<vector<int>> & skip, 
                vector<bool> & visited, 
                int start, 
                int len, int count,
                int m, int n) {
            // generate # of patterns from start   
            if (len >= m) {
                count ++;
            }
            len ++;
            if (len > n) {
                return count;
            }
            visited[start] = true;
            for (int i = 1; i < 9; ++i) {
                if (start == i) {
                    // skip self
                    continue;
                }
                if ((!visited[i]) &&
                    (skip[start][i] == 0 || visited[skip[start][i]])
                    ){
                    count = solve(skip, visited, i, len, count, m, n);
                }
            }
            visited[start] = false;
            return count;
        }

        int numberOfPatterns(int m, int n) {
            std::vector<vector<int>> skip (10, vector<int>(10, 0));
            skip[1][3] = skip[3][1] = 2;
            skip[1][7] = skip[7][1] = 4;
            skip[3][9] = skip[9][3] = 6;
            skip[7][9] = skip[9][7] = 8;
            skip[1][9] = skip[9][1] = 5;
            skip[2][8] = skip[8][2] = 5;
            skip[4][6] = skip[6][4] = 5;
            skip[7][3] = skip[3][7] = 5;
            
            std::vector<bool> visited (10, false);
            int res = 0;
            res += solve(skip, visited, 1, 1, 0, m, n) * 4;
            res += solve(skip, visited, 2, 1, 0, m, n) * 4;
            res += solve(skip, visited, 5, 1, 0, m, n);
            return res;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    return 0;
}

