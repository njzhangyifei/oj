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
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int num_row = matrix.size();
            if (num_row == 0) {
                return false;
            }
            int num_col = matrix[0].size();
            if (num_col == 0) {
                return false;
            }

            int i = 0;
            int j = num_col - 1;

            while (true) {
                if (i >= num_row || j < 0) {
                    return false;
                }
                if (matrix[i][j] == target) {
                    return true;
                }
                if (i == num_row-1 && j == 0) {
                    // cannot go down
                    return false;
                }
                if (i == num_row-1) {
                    j --;
                    continue;
                }
                if (j == 0) {
                    i ++;
                    continue;
                }
                if (matrix[i][j] > target) {
                    j --;
                } else {
                    i ++;
                }
            }

            return false;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

