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
using namespace std;

#define DEBUG

struct package {
    int ingredient;
    int total;
    int perserving;
    int minServing;
    int maxServing;

    package(int ingredient, 
            int total,
            int perserving,
            int min, int max){
        this->ingredient = ingredient;
        this->total = total;
        this->perserving = perserving;
        this->minServing = min;
        this->maxServing = max;
    }

    bool match(const package & ing) const {
        if (max(this->minServing, ing.minServing) <= min(this->maxServing, ing.maxServing)) {
            return true;
        }
        return false;
    }

    bool operator < (const package & y) const {
        return this->maxServing > y.maxServing;
    }

    package merge(const package & a, const package & b) const {
        int minServing = max(a.minServing, b.minServing);
        int maxServing = min(a.maxServing, b.maxServing);
        return package(-1, 0, 0, minServing, maxServing);
    }
};

void solve(int Tno){
    int N; // ingredient
    int P; // packages
    cin >> N >> P;

    std::map<int, priority_queue<package>> package_map;
    float minR[N];
    float maxR[N];
    float R[N];
    int i, j;
    for (i = 0; i < N; ++i) {
        cin >> R[i];
        minR[i] = 0.9 * R[i];
        maxR[i] = 1.1 * R[i];
        package_map[i] = priority_queue<package>();
    }

    int minServing[N][P];
    int maxServing[N][P];
    float Q[N][P];

    for (i = 0; i < N; ++i) {
        for (j = 0; j < P; ++j) {
            cin >> Q[i][j];
            maxServing[i][j] = (int)(Q[i][j] / minR[i]);
            minServing[i][j] = (int)(Q[i][j] / maxR[i]);
            package p(i, Q[i][j], R[i], minServing[i][j], maxServing[i][j]);
            package_map[i].push(p);
        }
    }


    // for (i = 0; i < N; ++i) {
    // }

    int maxkit = 0;
    bool GG = false;
    while (true) {
        for (i = 0; i < N; ++i) {
            if (package_map[i].size() == 0) {
                GG = true;
                break;
            }
        }
        if (GG) {
            break;
        }
        package root = package_map[0].top();
        int need_remove_index = 0;
        int need_remove_maxserveing = root.maxServing;
        bool matched = false;
        for (i = 1; i < N; ++i) {
            auto t = package_map[i].top();
            if (t.maxServing < need_remove_maxserveing) {
                need_remove_maxserveing = t.maxServing;
                need_remove_index = i;
            }
            #ifdef DEBUG
            cout << "trying ! " 
                << root.minServing << "/" << root.maxServing 
                << " -> "
                << t.minServing << "/" << t.maxServing ;
            #endif
            if (t.match(root)) {
                #ifdef DEBUG
                    cout << "matched";
                #endif
                root = t.merge(t, root);
                if (i == N-1) {
                    matched = true;   
                    #ifdef DEBUG
                        cout << "done";
                    #endif
                }
            } else {
                break;
            }
            #ifdef DEBUG
                cout << endl;
            #endif
        }
        if (matched) {
            for (i = 0; i < N; ++i) {
                package_map[i].pop();
            }
            maxkit ++;
        } else {
            package_map[need_remove_index].pop();
        }
    }


    #ifdef DEBUG
    for (i = 0; i < N; ++i) {
        for (j = 0; j < P; ++j) {
            cout << minServing[i][j] << "/" << maxServing[i][j] << " ";
        }
        cout << endl;
    }
    #endif

    cout << "Case #" << Tno << ":" << maxkit <<endl;
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

    return 0;
}

