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

#define DEBUG

using namespace std;

void solve(int Tno){
    int R, C;
    cin >> R >> C;
    char map[R][C];

    int i, j;
    for (i = 0; i < R; ++i) {
        string s;
        cin >> s;
        for (j = 0; j < C; ++j) {
            map[i][j] = s[j];
        }
    }

    bool DONE = true;
    for (i = 0; i < R; ++i) {
        for (j = 0; j < C; ++j) {
            if (map[i][j] == '?') {
                DONE = false;
                break;
            }
        }
    }

    if (DONE) {
        cout << "Case #" << Tno << ":" << endl;
        for (i = 0; i < R; ++i) {
            for (j = 0; j < C; ++j) {
                cout << map[i][j];
            }
            cout << endl;
        }
        return;
    } else {
        for (i = 0; i < R; ++i) {
            for (j = 0; j < C; ++j) {
                char ch = map[i][j];
                int k;
                for (k = j + 1; k < C; ++k) {
                    if (map[i][k] == '?') {
                        map[i][k] = ch;
                    } else {
                        break;
                    }
                }
            }
        }

        for (i = 0; i < R; ++i) {
            for (j = 0; j < C; ++j) {
                char ch = map[i][j];
                int k;
                for (k = j - 1; k >= 0; --k) {
                    if (map[i][k] == '?') {
                        map[i][k] = ch;
                    } else {
                        break;
                    }
                }
            }
        }


        for (i = 0; i < R; ++i) {
            for (j = 0; j < C; ++j) {
                char ch = map[i][j];
                int k;
                for (k = i + 1; k < R; ++k) {
                    if (map[k][j] == '?') {
                        map[k][j] = ch;
                    } else {
                        break;
                    }
                }
            }
        }

        for (i = 0; i < R; ++i) {
            for (j = 0; j < C; ++j) {
                char ch = map[i][j];
                int k;
                for (k = i - 1; k >= 0; --k) {
                    if (map[k][j] == '?') {
                        map[k][j] = ch;
                    } else {
                        break;
                    }
                }
            }
        }

        cout << "Case #" << Tno << ":" << endl;
        for (i = 0; i < R; ++i) {
            for (j = 0; j < C; ++j) {
                cout << map[i][j];
            }
            cout << endl;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    int i;
    for (i = 0; i < T; ++i) {
        solve(i+1);
    }
    return 0;
}

