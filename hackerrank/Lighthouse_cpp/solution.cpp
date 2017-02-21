#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <cmath>
#include <memory>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG

#ifdef DEBUG
#define print_map(...) print_map_real(__VA_ARGS__)
#else
#define print_map(...)
#endif

void print_map_real(int ** map, int N) {
    int i, j;
    cout << "map:" << endl;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (map[i][j] == -1) {
                cout << "X";
            } else {
                cout << map[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int ** copy_map(int ** map, int N){
    int i;
    int ** new_map = new int * [N];
    for (i = 0; i < N; ++i) {
        new_map[i] = new int [N];
        memcpy(new_map[i], map[i], N * sizeof(int));
    }
    return new_map;
}

void free_map(int ** map, int N){
    int i;
    for (i = 0; i < N; ++i) {
        delete map[i];
    }
    delete map;
}

int check_map_safe(int ** map, pair<int, int> coord, int N, int eq){
    int x = coord.first;
    int y = coord.second;
    if (x < 0 || x >= N) {
        return -1;
    }
    if (y < 0 || y >= N) {
        return -2;
    }
    if (map[x][y] == eq) {
        return 1;
    }
    return 0;
}

void print_map_to_check( std::map<int, std::vector<pair<int, int>> *> map_to_check ){
    for (auto i : map_to_check) {
        cout << "r = " << i.first << endl; 
        for (auto j : *(i.second)) {
            cout << "(" << j.first << "," << j.second << ")" << " ";
        }
        cout << endl;
    }
}

int solve(int *** map_ptr, int N){
    int ** map = *map_ptr;
    int i, j, gen;

    std::map<int, std::vector<pair<int, int>> *> map_to_check;
    for (gen = 0; gen < N; ++gen) {
        // generate map to check
        map_to_check.insert(
                pair<int, vector<pair<int, int>> *>(gen, new std::vector<pair<int, int>>())
                );
    }

    int x, y;
    for (x = 0; x < N; ++x) {
        for (y = 0; y < N; ++y) {
            gen = ceil(sqrt(x*x + y*y));
            if (gen >= N) {
                continue;
            }
            cout << "gen: " << gen << " x: " << x << " y: " << y << endl;
            map_to_check[gen]->push_back(pair<int, int>(x,y));
            map_to_check[gen]->push_back(pair<int, int>(y,-x));
            map_to_check[gen]->push_back(pair<int, int>(-x,-y));
            map_to_check[gen]->push_back(pair<int, int>(-y,x));
        }
    }
    
    // print_map_to_check(map_to_check);

    for (gen = 1; gen < (N / 2) + 1; ++gen) {
        // go through 0 to N
        int ** new_map = copy_map(map, N);
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                if (new_map[i][j] == gen-1) {
                    // find a center
                    bool ok = true; 
                    for (auto x : (*map_to_check[gen])) {
                        pair<int, int> to_check(x.first + i, x.second + j);
                        int res = check_map_safe(map, to_check, N, -1);
                        if (res == 1 || res < 0) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        // update
                        new_map[i][j] = gen;
                    }
                }
            }
        }
        free_map(map, N);
        map = new_map;
        print_map(map, N);
    }
    int ans = -1;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (map[i][j] > ans) {
                ans = map[i][j]; 
            }
        }
    }
    *map_ptr = map;
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;

    int ** map = new int * [N];

    int i, j;
    for (i = 0; i < N; ++i) {
        string s;
        cin >> s;
        map[i] = new int[N];
        for (j = 0; j < N; ++j) {
            map[i][j] = (s[j] == '*') ? -1 : 0;
        }
    }

    int ans = solve(&map, N);

    print_map(map, N);
    free_map(map, N);

    cout << ans;
    return 0;
}

