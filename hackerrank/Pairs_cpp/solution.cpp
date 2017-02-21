#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int diff_pair(int * input, int N, int K) {
    // go thru all
    sort(input+0, input+N);

    int num_pairs = 0;
    int i, j;

    // cout << "sorted_input:" << endl;
    // for (i = 0; i < N; ++i) {
        // cout << input[i] << " ";
    // }
    // cout << endl;

    i = 0;
    j = 1;
    while (j < N) {
        if (input[j] - input[i] == K) {
            num_pairs ++;
            i ++;
        } else if (input[j] - input[i] < K){
            j ++;
        } else {
            i ++;
        }
    }
    return num_pairs;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int K;
    cin >> N >> K;

    int * input = new int[N];
    int i;
    for (i = 0; i < N; ++i) {
        cin >> input[i];
    }

    cout << diff_pair(input, N, K);

    return 0;
}

