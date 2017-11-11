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
#include <iomanip>
#include <algorithm>
using namespace std;

void solve(int caseno){
    int N, M, P;
    cin >> N >> M >> P;

    int64_t graph[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            graph[i][j] = LONG_MAX;
        }
    }

    for (int i = 0; i < M; ++i) {
        int distance;
        int from, to;
        cin >> from >> to >> distance;
        from --; to --;
        graph[from][to] = distance;
        graph[to][from] = distance;
    }

    int64_t distance[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            distance[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (distance[i][k] == LONG_MAX || distance[k][j] == LONG_MAX) {
                    continue;
                }
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    unordered_map<int, double> except_distance;
    for (int i = 0; i < N; ++i) {
        except_distance[i] = 0;
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                except_distance[i] += distance[i][j];
            }
        }
    }

    std::vector<int64_t> count(N, 0);
    count[0] = 1;

    double res = 0;
    double contrib = 0;

    int i;
    for (i = 0; i < P; ++i) {
        double total = 0;
        double total_dist = 0;

        std::vector<int64_t> next_count(N);
        for (int _i = 0; _i < N; ++_i) {
            total += count[_i];
            total_dist += except_distance[_i] * count[_i];
            for (int _j = 0; _j < N; ++_j) {
                if (_i != _j) {
                    next_count[_j] += count[_i];
                }
            }
        }
        count = next_count;
        if ((total_dist / (total * (N-1))) == contrib) {
            break;
        }
        contrib = total_dist / (total * (N-1));
        res += contrib;
    }
    res += contrib * (P-i);

    cout << "Case #" << caseno << ": " << std::fixed << std::setprecision(6) << 
        res << endl;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve(i+1);
    }
    return 0;
}

