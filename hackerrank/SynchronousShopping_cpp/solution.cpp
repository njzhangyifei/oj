#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

// #define DEBUG
#define FISH(x)  (1 << (x-1))

using namespace std;

std::set<pair<int, pair<int, int>>> v_set;
int solve(uint16_t ** map, uint16_t * shops, int N, int M, int K) {
    int i, j, k;
    int ** dist = new int * [N];

    for (i = 0; i < N; ++i) {
        dist[i] = new int[(1<<K)];
    }
    for (i = 0; i < N; ++i) {
        for (j = 0; j < (1<<K); j++) {
            dist[i][j] = INT_MAX;
        }
    }

    pair<int, pair<int, int>> source;
    source.first = 0; // dist
    source.second.first = 0;
    source.second.second = shops[0];
    dist[source.second.first][source.second.second] = 0;
    
    v_set.insert(source);

    while (v_set.size()) {
        pair<int, pair<int, int>> p = *v_set.begin();
        v_set.erase(v_set.begin());
        int current_dist = p.first;
        int current_node = p.second.first;
        int current_fish = p.second.second;
        for (i = 0; i < N; ++i) {
            if (map[current_node][i] == 0) {
                // no edge
                continue;
            }
            int weight = map[current_node][i];
            int dest_dist = current_dist + weight;
            int dest_fish = current_fish | shops[i];
            if (dist[i][dest_fish] > dest_dist) {
                pair<int, pair<int, int>> dest;
                dest.first = dist[i][dest_fish];
                dest.second.first = i;
                dest.second.second = dest_fish;
                v_set.erase(dest);
                dest.first = dest_dist;
                dist[i][dest_fish] = dest_dist;
                v_set.insert(dest);
            }
        }
    }


    #ifdef DEBUG
    for (i = 0; i < N; ++i) {
        cout << "dist[" << i << "] ";
        for (j = 0; j < (1<< K); ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << -1 << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    #endif

    int ans = INT_MAX;
    for (i = 0; i < (1<<K); ++i) {
        for (j = 0; j < (1<<K); ++j) {
            if ((i | j) == ((1 << K) -1)) {
                ans = min(ans, max(dist[N-1][i], dist[N-1][j]));
            }
        }
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M, K;
    cin >> N >> M >> K;

    uint16_t * shops = new uint16_t[N];
    memset(shops, 0, sizeof(uint16_t) * N);

    int i, j;
    for (i = 0; i < N; ++i) {
        int num_fish;
        cin >> num_fish;
        for (j = 0; j < num_fish; ++j) {
            int fish_type;
            cin >> fish_type;
            shops[i] |= FISH(fish_type);
        }
    }

    uint16_t ** map = new uint16_t * [N];
    for (i = 0; i < N; ++i) {
        map[i] = new uint16_t[N];
        memset(map[i], 0, sizeof(uint16_t) * N);
    }

    for (i = 0; i < M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        from --; to --;
        map[from][to] = weight;
        map[to][from] = weight;
    }


    cout << solve(map, shops, N, M, K) << endl;

    return 0;
}

