#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n, int expected) {
    int num[n];
    int sum[expected + 1];
    memset(sum, 0, sizeof(int) * (expected+1));

    int i, j;
    for (i = 0; i < n; ++i) {
        cin >> num[i];
        if (num[i] <= expected) {
            sum[num[i]] = num[i];
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = num[i]; j <= expected; ++j) {
            // for every integer
            int prev = j - num[i];
            if (sum[prev] + num[i] <= expected) {
                sum[j] = max(sum[prev] + num[i], sum[j]);
            }
        }
    }

    for (i = 0; i <= expected; ++i) {
        cout << sum[i] << " ";
    }
    cout << endl;

    return sum[expected];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T;
    cin >> T;

    int i;
    for (i = 0; i < T; ++i) {
        int n, k;
        cin >> n >> k;
        int res = solve(n,k);
        cout << res << endl;
    }

    return 0;
}

