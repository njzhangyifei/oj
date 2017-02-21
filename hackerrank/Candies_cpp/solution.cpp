#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int generate_distribution_sum(int ratings_fixed[], int N);

std::vector<int> vallies;
int solve(int ratings[], int N){
    int i;
    int ratings_fixed[N+2];
    ratings_fixed[0] = INT_MAX;
    for (i = 0; i < N; ++i) {
        ratings_fixed[i+1] = ratings[i];
    }
    ratings_fixed[N+1] = INT_MAX;

    for (i = 1; i < N+1; ++i) {
        int current_rating = ratings_fixed[i];
        int prev_rating = ratings_fixed[i-1];
        int next_rating = ratings_fixed[i+1];
        if (prev_rating >= current_rating &&
            next_rating >= current_rating) {
            // this is a valley
            vallies.push_back(i-1);
        }
    }

    return generate_distribution_sum(ratings_fixed, N);
}

int generate_distribution_sum(int ratings_fixed[],  int N){
    int distribution[N];
    memset(distribution, 0, N * sizeof(int));

    while (vallies.size()) {
        int i;
        int index = vallies.back();
        int count;
        distribution[index] = 1;
        count = 1;
        for (i = index; i < N; ++i) {
            int current_rating = ratings_fixed[i+1];
            int next_rating = ratings_fixed[i+2];
            distribution[i] = max(count++, distribution[i]);
            if (current_rating >= next_rating) {
                // we've reached a local maxima
                break;
            }
        }

        count = 1;
        for (i = index; i >= 0; --i) {
            int current_rating = ratings_fixed[i+1];
            int prev_rating = ratings_fixed[i];
            distribution[i] = max(count++, distribution[i]);
            if (current_rating >= prev_rating) {
                // we've reached a local maxima
                //   *
                // ****
                // ******
                //   ^
                // 114321
                break;
            }
        }

        vallies.pop_back();
    }

    int sum = 0;
    int i;
    for (i = 0; i < N; ++i) {
        // cout << i << " rating " << ratings_fixed[i+1] << " -> " << distribution[i];
        // cout << endl;
        sum += distribution[i];
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N,i ;
    cin >> N;

    int ratings[N];
    for (i = 0; i < N; ++i) {
        cin >> ratings[i];
    }

    int sum = solve(ratings, N);

    cout << sum;

    return 0;
}

