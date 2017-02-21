#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

#define DEBUG
using namespace std;

int solve(vector<int> v) {
    uint32_t N = v.size();
    uint64_t left_sum;
    uint64_t right_sum;
    uint32_t i,j,k;
    uint32_t left_start;
    uint32_t left_end;

    int score = 0;
    bool game_over = false;

    sort(v.begin(), v.end(), std::greater<int>());

    #ifdef DEBUG
    cout << N;
    // cout << "sorted v:" << endl;
    // for (auto i : v) {
        // cout << i << " ";
    // }
    // cout << endl;
    #endif

    int total = 0;
    for (i = 0; i < N; ++i) {
        total += v[i];
    }

    if (total % 2) {
        // score 0
        return 0;
    }

    int expected_sum = total / 2;
    int current_sum = 0;
    for (i = 0; i < N; ++i) {
    }
    

    return score;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;

    int i, j;
    for (i = 0; i < T; ++i) {
        int N;
        cin >> N;
        std::vector<int> v;
        for (j = 0; j < N; ++j) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        cout << solve(v) << endl;
    }

    return 0;
}

