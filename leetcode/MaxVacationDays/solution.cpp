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

lass Solution
{
    public:
        int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
            int num_cities = days.size();
            int num_weeks = days[0].size();

            std::vector<vector<int>> dp 
                (num_weeks, vector<int>(num_cities, INT_MIN));

            dp[0][0] = 0;
            for (int i = 0; i < num_weeks; ++i) {
                for (int j = 0; j < num_cities; ++j) {
                    if (i == 0) {
                        bool hasFlight = flights[0][j] || j==0;
                        if (hasFlight) dp[i][j] = days[j][i];
                    }
                    for (int k = 0; k < num_cities; ++k) {
                        bool hasFlight = flights[k][j] || j==k;
                        if (hasFlight && i > 0) {
                            dp[i][j] = max(dp[i-1][k] + days[j][i], dp[i][j]);
                        }
                    }
                }
            }
            int res = 0;
            for (int i = 0; i < num_cities; ++i) {
                res = max(res, dp[num_weeks-1][i]);
            }

            return res;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

