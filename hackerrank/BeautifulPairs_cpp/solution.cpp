#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

#define DEBUG

using namespace std;

int solve(int N, int * A, int * B){
    int * frequency = new int[1001];
    int i, j;
    for (i = 0; i < 1001; ++i) {
        frequency[i] = 0;
    }

    for (i = 0; i < N; ++i) {
        int a_val = A[i];
        frequency[a_val] ++;
    }

    for (i = 0; i < N; ++i) {
        int b_val = B[i];
        if (frequency[b_val]) {
            frequency[b_val]--;
        }
    }

    int disjoint_pair_count = N;
    for (i = 0; i < 1001; ++i) {
        disjoint_pair_count -= frequency[i];
    }


    disjoint_pair_count += (disjoint_pair_count == N) ? -1 : 1;

    #ifdef DEBUG
    cout << "disjoint_pair_count: " << disjoint_pair_count << endl;
    #endif

    delete frequency;
    return disjoint_pair_count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int i;
    cin >> N;
    int * A = new int[N];
    int * B = new int[N];
    for (i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (i = 0; i < N; ++i) {
        cin >> B[i];
    }
    int res = solve(N, A, B);
    cout << res;
    delete A;
    delete B;
    return 0;
}

