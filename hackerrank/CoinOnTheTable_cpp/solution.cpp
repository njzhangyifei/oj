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

void replace_safe( uint16_t *** dp, 
        int N, int M,
        int x, int y,
        int epoch, 
        uint16_t val) {
    if (x < 0 || x >= N) {
        return;
    }
    if (y < 0 || y >= M) {
        return;
    }
    dp[x][y][epoch] = min(dp[x][y][epoch], val);
}

bool fill_for(char ** map, int N, int M,
        uint16_t *** dp, int x, int y, int epoch, int K) {
    if (epoch >= K) {
        return false;
    }
    char ch = map[x][y];
    uint16_t mods_now = dp[x][y][epoch];
    if (ch == 'R') {
        replace_safe(dp, N, M, x, y+1, epoch + 1, mods_now);
    } else if (ch == 'L') {
        replace_safe(dp, N, M, x, y-1, epoch + 1, mods_now);
    } else if (ch == 'D') {
        replace_safe(dp, N, M, x+1, y, epoch + 1, mods_now);
    } else if (ch == 'U') {
        replace_safe(dp, N, M, x-1, y, epoch + 1, mods_now);
    } else if (ch == '*') {
        return false;
    }
    replace_safe(dp, N, M, x+1, y, epoch + 1, mods_now + 1);
    replace_safe(dp, N, M, x-1, y, epoch + 1, mods_now + 1);
    replace_safe(dp, N, M, x, y+1, epoch + 1, mods_now + 1);
    replace_safe(dp, N, M, x, y-1, epoch + 1, mods_now + 1);
    return true;
}

int solve(char ** map, int N, int M, int K) {
    int i, j;
    int dest_x, dest_y;

    uint16_t *** dp = new uint16_t ** [N];
    for (i = 0; i < N; ++i) {
        dp[i] = new uint16_t * [M];
        for (j = 0; j < M; ++j) {
            dp[i][j] = new uint16_t[K+1];
            if (map[i][j] == '*') {
                dest_x = i;
                dest_y = j;
            }
            memset(dp[i][j], 0xFFFF, sizeof(uint16_t) * (K+1));
        }
    }

    dp[0][0][0] = 0;
    int epoch;
    for (epoch = 0; epoch < K+1; ++epoch) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < M; ++j) {
                if (epoch >= 1) {
                    dp[i][j][epoch] = min(dp[i][j][epoch], dp[i][j][epoch-1]);
                }
                if (dp[i][j][epoch] != 0xFFFF) {
                    fill_for(map, N, M, dp, i, j, epoch, K);
                }
            }
        }
    }
    
    #ifdef DEBUG
    for (epoch = 0; epoch < K+1; ++epoch) {
        cout << "dp table: epoch " << epoch << endl;
        for (i = 0; i < N; ++i) {
            for (j = 0; j < M; ++j) {
                cout << dp[i][j][epoch] << " ";
            }
            cout << endl;
        }
    }
    #endif

    int rtnval = dp[dest_x][dest_y][K];
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            delete dp[i][j];
        }
        delete dp[i];
    }
    delete dp;

    if (rtnval == 0xFFFF) {
        rtnval = -1;
    }

    #ifdef DEBUG
    cout << rtnval << endl;
    #endif

    return rtnval;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M, K;
    cin >> N >> M >> K;

    char ** map = new char * [N];
    int i, j;
    for (i = 0; i < N; ++i) {
        map[i] = new char[M];
    }
    for (i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (j = 0; j < M; ++j) {
            map[i][j] = s[j];
        }
    }

    #ifdef DEBUG
    cerr << "map:" << endl;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    #endif
    
    cout << solve(map, N, M, K) << endl;

    for (i = 0; i < N; ++i) {
        delete map[i];
    }
    delete map;

    return 0;
}

