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
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int m = matrix.size();
            if (m == 0) {
                return vector<int>();
            }
            int n = matrix[0].size();

            vector<int> ans (m * n);
            int curr = 0;
            int u = 0, d = m-1, r = n-1, l = 0;

            while (true) {
                // right
                for (int col = l; col <= r; ++col) {
                    ans[curr++] = matrix[u][col];
                }
                if (++u > d) { break; }

                // down
                for (int row = u; row <= d; ++row) {
                    ans[curr++] = matrix[row][r];
                }
                if (--r < l) { break; }

                // left
                for (int col = r; col >= l; --col) {
                    ans[curr++] = matrix[d][col];
                }
                if (--d < u) { break; }

                // up
                for (int row = d; row >= u; --row) {
                    ans[curr++] = matrix[row][l];
                }
                if (++l > r) { break; }
            }
            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

