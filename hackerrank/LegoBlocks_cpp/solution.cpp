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

int safe_access(int * table, int length, int i) {
    if (i < 0 || i >= length) {
        return 0;
    }
    return table[i];
}

uint8_t blocks [4] = {1, 2, 3, 4};
void solve() {
    int N, M;
    // N = height, M = width
    cin >> N >> M;

    int * dp_width = new int[1001];
    int * num_nonsolid = new int[1001];
    int * num_solid = new int[1001];
    memset(dp_width, 0, 1001 * (sizeof(int)));
    memset(num_nonsolid, 0, 1001 * (sizeof(int)));
    memset(num_solid, 0, 1001 * (sizeof(int)));

    int i, j;
    for (i = 0; i < 4; ++i) {
        dp_width[blocks[i]] = 1;
    }

    // 1   1+1=2   1+2+1=3
    for (i = 1; i <= M; ++i) {
        for (j = 0; j < 4; ++j) {
            dp_width[i] = 
                (((int64_t)dp_width[i]) + safe_access(dp_width, M, i - blocks[j])) %
                1000000007;
        }
        num_nonsolid[i] = 1;
        for (j = 0; j < N; ++j) {
            num_nonsolid[i] = 
                (int)((((int64_t)num_nonsolid[i]) * dp_width[i]) % 1000000007);
        }
    }

    num_solid[1] = num_nonsolid[1];
    for (i = 2; i <= M; ++i) {
        int diff = 0;
        for (j = 1; j < i; ++j) {
            int add = 
                (int)((((int64_t)num_solid[j]) * num_nonsolid[i-j]) % 1000000007); 
            diff = (int)((((int64_t)diff) + add) % 1000000007);
        }
        num_solid[i] = (num_nonsolid[i] - diff + 1000000007) % 1000000007;
    }
    
    #ifdef DEBUG
    cout << "dp_width:" << endl;
    for (i = 1; i <= M; ++i) {
        cout << dp_width[i] << " ";
    }
    cout << endl;
    cout << "num_nonsolid:" << endl;
    for (i = 1; i <= M; ++i) {
        cout << num_nonsolid[i] << " ";
    }
    cout << endl;
    cout << "num_solid:" << endl;
    for (i = 1; i <= M; ++i) {
        cout << num_solid[i] << " ";
    }
    cout << endl;
    #endif

    cout << num_solid[M] << endl;

    delete dp_width;
    delete num_solid;
    delete num_nonsolid;
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

