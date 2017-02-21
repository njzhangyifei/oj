#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int8_t check_map_safe(int i, int j, uint8_t ** map, int N, int M) {
    if (i < 0 || i >= N) {
        return -1;
    } 
    if (j < 0 || j >= M) {
        return -1;
    }
    if (map[i][j] == 'X') {
        return -1;
    } else {
        return 0;
    }
}

int dfs(pair<int,int> current, uint8_t ** map, int N, int M, uint8_t ** visited, 
        int32_t * res
        ) {
    // do dfs
    int current_i; int current_j;
    current_i = current.first;
    current_j = current.second;

    if (visited[current_i][current_j]) {
        return -2;
    }
    visited[current_i][current_j] = 1;


    if (map[current_i][current_j] == '*') {
        return 1;
    }
    
    // up
    int8_t up =check_map_safe(current_i-1, current_j, map, N, M);
    int8_t down =check_map_safe(current_i+1, current_j, map, N, M);
    int8_t left =check_map_safe(current_i, current_j-1, map, N, M);
    int8_t right =check_map_safe(current_i, current_j+1, map, N, M);

    // if more than one, use the wand
    uint8_t ways = 0;
    if (up >= 0 && !visited[current_i-1][current_j]) {
        ways += 1;
    }
    if (down >= 0 && !visited[current_i+1][current_j]) {
        ways += 1;
    }
    if (left >= 0 && !visited[current_i][current_j-1]) {
        ways += 1;
    }
    if (right >= 0 && !visited[current_i][current_j+1]) {
        ways += 1;
    }
    if (ways > 1) {
        // more than one
        (*res) += 1;
    }

    int result;
    if (up >= 0) {
        result = dfs(pair<int, int>(current_i-1, current_j), map, N, M, visited, res);
        if (result > 0) {
            return result;
        }
    }
    if (down >= 0) {
        result = dfs(pair<int, int>(current_i+1, current_j), map, N, M, visited, res);
        if (result > 0) {
            return result;
        }
    }
    if (left >= 0) {
        result = dfs(pair<int, int>(current_i, current_j-1), map, N, M, visited, res);
        if (result > 0) {
            return result;
        }
    }
    if (right >= 0) {
        result = dfs(pair<int, int>(current_i, current_j+1), map, N, M, visited, res);
        if (result > 0) {
            return result;
        }
    }

    // wand is wrong
    if (ways > 1) {
        (*res) -= 1;
    }
    return -1;
} 

void solve(uint8_t ** map, int N, int M, int K,
            pair<int, int> root, pair<int, int> target) {
    int i;
    uint8_t ** visited = new uint8_t * [N];
    for (i = 0; i < N; ++i) {
        visited[i] = new uint8_t[M];
        memset(visited[i], 0, M);
    }

    int32_t res = 0;
    int rtn = dfs(root, map, N, M, visited, &res);
    if (rtn > 0) {
        if (K == res) {
            cout << "Impressed" << endl;
        } else {
            cout << "Oops!" << endl;
        }
    }

    for (i = 0; i < N; ++i) {
        delete visited[i];
    }
    delete visited;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int T;
    cin >> T;

    int e;
    for (e = 0; e < T; ++e) {
        int i;
        int j;
        int N; int M;
        cin >> N >> M;

        uint8_t ** map = new uint8_t * [N];
        for (i = 0; i < N; ++i) {
            map[i] = new uint8_t[M];
            memset(map[i], 0x00, M);
        }

        string s;
        pair<int, int> root;
        pair<int, int> target;
        for (j = 0; j < N; ++j) {
            cin >> s;
            int k;
            for (k = 0; k < M; ++k) {
                map[j][k] = s[k];
                if (s[k] == 'M') {
                    root.first = j;
                    root.second = k;
                } else if (s[k] == '*'){
                    target.first = j;
                    target.second = k;
                }
            }
        }

        int K;
        cin >> K;

        solve(map, N, M, K, root, target);

        for (i = 0; i < N; ++i) {
            delete map[i];
        }
        delete map;
    }
    return 0;
}

