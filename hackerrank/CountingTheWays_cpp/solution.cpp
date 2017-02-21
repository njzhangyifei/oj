#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int solve(vector<int> * v, int N, int L, int R) {
    int * res = new int[R+1];
    memset(res, 0, (R+1) * sizeof(int));

    res[0] = 1;

    int i; 
    int j;

    for (i = 0; i < N; ++i) {
        for (j = (*v)[i]; j <= R; ++j) {
            res[j] = ((uint64_t)res[j] + (uint64_t)res[j-(*v)[i]]) % MOD;
            // using j=> j-v[i]
            // j = v[i] -> R
        }
    }

    // for (i = 0; i < R+1; ++i) {
        // cout << res[i] << " ";
    // }
    // cout << endl;

    int64_t sum = 0;
    for (i = L; i <= R; ++i) {
        sum += res[i];
        sum %= MOD;
    }

    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N;
    cin >> N;

    int i;
    std::vector<int> v;

    for (i = 0; i < N; ++i) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int L, R;
    cin >> L >> R;

    cout << solve(&v, N, L, R) << endl;
    return 0;
}

