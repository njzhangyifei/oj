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
    int numSquares(int n) {
        vector<int> dp (n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i) {
            for (int j = i*i; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j-i*i] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

