#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = {0, 1, 1};
int dy[] = {1, 0, -1};

uint8_t is_safe(int N, int x, int y){
    if (x < 0 || x >= N) {
        return false;
    }
    if (y < 0 || y >= 2) {
        return false;
    }
    return true;
}

uint8_t found;
void solve(int N, int * first, int * second) {
    uint8_t done = false;
    int i, j, k;
    int * map[] = {first, second};
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < N; ++j) {
            if (map[i][j] == 0) {
                done = true;
                for (k = 0; k < 3; ++k) {
                    if (found) {
                        break;
                    }
                    int next_y = i + dx[k];
                    int next_x = j + dy[k];
                    if (is_safe(N, next_x, next_y) && map[next_y][next_x] == 0)
                    {
                        // we are good
                        map[i][j] = 1;
                        map[next_y][next_x] = 1;
                        solve(N, first, second);
                        map[i][j] = 0;
                        map[next_y][next_x] = 0;
                    }
                }
            }
        }
    }
    if (!done) {
        found = true;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;

    cin >> T;

    int i, j;
    for (i = 0; i < T; ++i) {
        int N;
        cin >> N;
        string first_str, second_str;
        cin >> first_str >> second_str;
        int first[N];
        int second[N];
        for (j = 0; j < N; ++j) {
            first[j] = first_str[j] - '0';
            second[j] = second_str[j] - '0';
        }
        found = false;
        solve(N, first, second);
        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

