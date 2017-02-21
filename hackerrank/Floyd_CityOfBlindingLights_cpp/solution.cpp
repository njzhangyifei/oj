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

void solve(int N, int ** graph){
    int i, j, k;
    int ** map = new int * [N];
    for (i = 0; i < N; ++i) {
        map[i] = new int[N];
        for (j = 0; j < N; ++j) {
            map[i][j] = INT_MAX;
        }
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (i == j) {
                map[i][j] = 0;
            } else if (graph[i][j] != INT_MAX) {
                map[i][j] = graph[i][j];
            }
        }
    }

    for (k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                int64_t path_via_k = ((int64_t)map[i][k] + map[k][j]);
                if (path_via_k > INT_MAX) {
                    path_via_k = INT_MAX;
                }
                if (map[i][j] > path_via_k) {
                    map[i][j] = path_via_k;
                }
            }
        }
    }

    #ifdef DEBUG
    for (i = 0; i < N; ++i) {
        cout << "[" << i << "] ";
        for (j = 0; j < N; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    #endif
    
    int Q;
    cin >> Q;
    for (i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (map[a][b] == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << map[a][b] << endl;
        }
    }

    for (i = 0; i < N; ++i) {
        delete map[i];
    }
    delete map;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M;
    cin >> N >> M;

    int i, j;

    int ** graph = new int * [N];
    for (i = 0; i < N; ++i) {
        graph[i] = new int[N];
        for (j = 0; j < N; ++j) {
            graph[i][j] = INT_MAX;
        }
    }

    for (i = 0; i < M; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        x--;
        y--;
        graph[x][y] = r;
    }

    solve(N, graph);
    
    for (i = 0; i < N; ++i) {
        delete graph[i];
    }
    delete graph;
    return 0;
}

