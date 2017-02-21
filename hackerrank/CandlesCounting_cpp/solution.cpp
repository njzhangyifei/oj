#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

#define DEBUG

#define COLOR(x) (1 << (colors[x]-1))

#define FENWICK_INDEX(x)    (x+1)
#define FENWICK_NEXT(x)     (x + ((-x) & x))
#define FENWICK_PARENT(x)   (x - ((-x) & x))

int fenwick[50010][256];

int fenwick_query(uint32_t n, uint8_t color){
    uint32_t index = n+1;
    int64_t sum = 0;
    while (true) {
        if (index <= 0) {
            break;
        }
        sum = (sum + fenwick[index][color]) % MOD;
        index = FENWICK_PARENT(index);
    }
    return sum;
}

void fenwick_update(uint32_t n, int val, uint8_t color){
    uint32_t index = n+1;
    while (true) {
        if (index > 50002) {
            break;
        }
        fenwick[index][color] = 
            ((int64_t)(fenwick[index][color]) + val) % MOD;
        index = FENWICK_NEXT(index);
    }
}

void solve_num_inclusionexclusion
(int N, int K, uint8_t * colors, uint16_t * heights) {
    int i, j, k;

    int64_t res = 0;
    for (j = 0; j < (1<<K); ++j) {
        memset(fenwick, 0, 50010 * 256 * sizeof(int));
        int64_t tmp = 0;
        for (i = 0; i < N; ++i) {
            if (j & COLOR(i)) {
                int64_t val = 1;
                val += fenwick_query(heights[i]-1, 0);
                val %= MOD;
                fenwick_update(heights[i], val, 0);
                tmp += val;
                tmp %= MOD;
            }
        }
        if (__builtin_popcount(j) % 2 == (K) % 2) {
            // add
            res = (res + tmp) % MOD;
        } else {
            // subtract
            res = (res - tmp + MOD) % MOD;
        }
    }

    #ifdef DEBUG
    // cout << "fenwick query:" << endl;
    cout << res << endl;
    #endif
}

void solve_num_bitmask(int N, int K, uint8_t * colors, uint16_t * heights) {
    int i, j, k;

    fenwick_update(0,1,0);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < (1 << K); ++j) {
            // for all color we find val=height
            int val = fenwick_query(heights[i]-1, j) % MOD;
            // add this val to the index, at the same time, maintain the tree
            fenwick_update(heights[i], val, j | COLOR(i));
        }
    }

    uint8_t all_color = (1 << (K)) - 1;

    #ifdef DEBUG
    // cout << "fenwick query:" << endl;
    cout << fenwick_query(50002, all_color) << endl;
    #endif
}

void solve(int N, int K, uint8_t * colors, uint16_t * heights) {
    solve_num_inclusionexclusion(N, K, colors, heights);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, K;
    cin >> N >> K;

    uint8_t * colors = new uint8_t[N];
    uint16_t * heights = new uint16_t[N];

    int i;
    for (i = 0; i < N; ++i) {
        int color, height;
        cin >> height >> color;
        heights[i] = height;
        colors[i] = color;
    }
    
    solve(N, K, colors, heights);
    return 0;
}

