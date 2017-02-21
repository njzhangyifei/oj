#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

void solve() {
    int i, j, k;
    int N;
    cin >> N;

    int * B = new int[N];
    for (i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int ** dp = new int * [N];
    for (i = 0; i < N; ++i) {
        dp[i] = new int[2];
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    for (i = 1; i < N; ++i) {
        // go thru all element

        // if A_i == 1
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + abs(B[i-1] - 1)); 

        // if A_i == B_i
        dp[i][1] = max(dp[i-1][0] + abs(B[i]-1), dp[i-1][1] + abs(B[i] - B[i-1]));
    }

    int rtnval = max(dp[N-1][0], dp[N-1][1]);

    for (i = 0; i < N; ++i) {
        #ifdef DEBUG
        cout << dp[i][0] << " " << dp[i][1] << endl;
        #endif
        delete dp[i];
    }
    delete dp;
    delete B;

    cout << rtnval << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    
    int i;
    for (i = 0; i < T; ++i) {
        solve();
    }

    return 0;
}

