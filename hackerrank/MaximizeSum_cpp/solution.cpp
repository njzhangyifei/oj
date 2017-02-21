#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iterator>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

int64_t solve(int N, int64_t M, int64_t * input)
{
    int i, j;
    int64_t * prefix_mod = new int64_t[N];
    std::set<pair<int64_t, int>> s;
    prefix_mod[0] = input[0] % M;
    for (i = 1; i < N; ++i) {
        prefix_mod[i] = (input[i] + prefix_mod[i-1]) % M;
    }
    #ifdef DEBUG
    cout << "prefix_mod:" << endl;
    for (i = 0; i < N; ++i) {
        cout << prefix_mod[i] << " ";
    }
    cout << endl;
    #endif
    for (i = 0; i < N; ++i) {
        s.insert(pair<int64_t, int>(prefix_mod[i], i));
    }
    int64_t max_mod = 0;
    for (i = 0; i < N; ++i) {
        max_mod = max(prefix_mod[i], max_mod);
    }
    for (i = 0; i < N; ++i) {
        std::set<pair<int64_t, int>>::iterator t = 
            s.upper_bound(pair<int64_t, int>(prefix_mod[i], i));
        if (t != s.end()) {
            // we found a iterator with larger mod and smallest index
            pair<int64_t, int> p = *t;
            if (p.second < i) {
                #ifdef DEBUG
                cout << "found:" << prefix_mod[i] << ", " << p.first << endl;
                #endif
                max_mod = max(max_mod, (M-(p.first- prefix_mod[i])) % M);
            }
        }
    }
    delete prefix_mod;
    return max_mod;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;

    int i, j;
    for (i = 0; i < T; ++i) {
        int N;
        int64_t M;
        cin >> N >> M;
        
        int64_t * input = new int64_t[N];
        for (j = 0; j < N; ++j) {
            cin >> input[j];
        }
        int64_t res = solve(N, M, input);
        cout << res << endl;
        delete input;
    }
    return 0;
}

