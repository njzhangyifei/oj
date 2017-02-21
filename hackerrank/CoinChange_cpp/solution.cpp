#include <cmath>
#include <cstdio>
#include <vector>
#include <cinttypes>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M;
    cin >> N >> M;
    int value[M];
    int i, j;
    for (i = 0; i < M; ++i) {
        cin >> (value[i]);
    }

    int64_t count[N+1]; // number of ways for each remaining value
    memset(count, 0, sizeof(int64_t) * (N+1));
    // we have 1 method only for those requires $0 reamining as change
    count[0] = 1;

    // pick a coint to start
    for (i = 0; i < M; ++i) {
        // j = coin value
        for (j = value[i]; j <= N; ++j) {
            // start with the coin we pick, compute until the target value
            
            // total for a value (selected + iterator)
            //      = previous_total + 
            //        count for the reamining 
            //        (value added by the iterator)
            uint8_t reamining_change = j - value[i];
            count[j] += count[reamining_change];
        }
    }

    // generate output
    cout << count[N] << endl;
    return 0;
}
