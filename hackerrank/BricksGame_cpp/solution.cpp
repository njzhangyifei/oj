#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

// #define DEBUG
void solve() {
    int N;
    cin >> N;

    int bricks[N];
    int64_t post_sum[N];
    int64_t score_dp[N];
    memset(score_dp, INT_MIN, sizeof(int64_t) * N);

    int i, j, k;
    for (i = 0; i < N; ++i) {
        cin >> bricks[i];
    }

    int64_t temp = 0;
    for (i = N-1; i >= 0; --i) {
        temp += bricks[i];
        post_sum[i] = temp;
    }

    // n -> the start of sequence
    // optimal choice for f(n, choice) = min(f(n-choice, 1), f(n-choice, 2), f(n-choice, 3))
    
    for (i = N-1; i >= N-3; --i) {
        score_dp[i] = post_sum[i];
    }
   
    for (i = N-4; i >= 0; --i) {
        for (j = 1; j <= 3; ++j) {
            score_dp[i] = max(score_dp[i], post_sum[i] - score_dp[i + j]); 
        }
    }

#ifdef DEBUG
    for (i = 0; i < N; ++i) {
        cout << bricks[i] << " ";
    }
    cout << endl;

    cout << "post-fix table:" << endl;
    for (i = 0; i < N; ++i) {
        cout << post_sum[i] << " ";
    }
    cout << endl;

    cout << "dp table:" << endl;
    for (i = 0; i < N; ++i) {
        cout << score_dp[i] << " ";
    }
    cout << endl;
    cout << endl;

#endif

    cout << score_dp[0] << endl;
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

