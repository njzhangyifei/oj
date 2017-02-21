#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cinttypes>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int ratings[], int N){
    int i;
    int distribution[N];
    memset(distribution, 1, N);
    distribution[0] = 1;
    for (i = 1; i < N; ++i) {
        if (ratings[i-1] < ratings[i]) {
            // we need to give one more than the last
            distribution[i] = distribution[i-1] + 1;
        } else {
            distribution[i] = 1;
        }
    }
    for (i = 1; i < N; ++i) {
        int j = N - i - 1;
        if (ratings[j] > ratings[j+1]) {
            // we need to give one more than the last
            distribution[j] = max(distribution[j], distribution[j+1] + 1);
        }
    }
    int sum = 0;
    for (i = 0; i < N; ++i) {
        sum += distribution[i];
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N;
    cin >> N;
    
    int ratings[N];
    int i;
    for (i = 0; i < N; ++i) {
        cin >> ratings[i];
    }

    int sum = solve(ratings, N);

    cout << sum;

    return 0;
}

