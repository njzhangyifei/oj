#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp(int ratings[], int N) {
    int distribution[N];
    int i, j;
    distribution[0] = 1;
    for (i = 1; i < N; ++i) {
        if (ratings[i] > ratings[i-1]) {
            distribution[i] = distribution[i-1] + 1;
        // } else if (distribution[i-1] == 1){
        } else {
            // we cannot be sure about dist[i-1] is still correct 
            // need to check from the right hand side
            distribution[i] = 1;
            for (j = i-1; j >= 0; --j) {
                if (ratings[j] > ratings[j+1]) {
                    // distribution at j(from i-1 iterating) is not correct
                    //   need to update this
                    distribution[j] = 
                        max(distribution[j+1] + 1, distribution[j]);
                } else {
                    // we are fine/everything fixed, distribution[j] has
                    // become the local maxima
                    break;
                }
            }
        // } else {
            // distribution[i] = 1;
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
    int max_rating;
    int i;
    max_rating = 0;
    for (i = 0; i < N; ++i) {
        cin >> ratings[i];
    }

    cout << dp(ratings, N);

    return 0;
}

