#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

#define DEBUG

using namespace std;
int solve(int * input, int N, int k){
    if (k == 1 || N == 2) {
        return 0;
    }
    int * mod_count = new int [k];
    memset(mod_count, 0, k * sizeof(int));
    int i = 0;
    for (i = 0; i < N; ++i) {
        int mod = input[i] % k;
        mod_count[mod] ++;
    }
    
    int length = 0;
    for (i = 1; i < (k/2 + k%2); ++i) {
        if (mod_count[i] > mod_count[k-i]) {
            length += mod_count[i];
        } else {
            length += mod_count[k-i];
        }
    }

    if (mod_count[0]) {
        length += 1;
    }

    uint8_t is_odd = k % 2;
    if (!is_odd) {
        length += 1;
    }

    #ifdef DEBUG
    cout << "mod_count:" << endl;
    for (i = 0; i < k; ++i) {
        cout << mod_count[i] << " ";
    }
    cout << endl;
    #endif

    return length;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, k;
    cin >> N >> k;
    int * input = new int[N];
    int i;
    for (i = 0; i < N; ++i) {
        cin >> input[i];
    }
    cout << solve(input, N, k);
    return 0;
}

