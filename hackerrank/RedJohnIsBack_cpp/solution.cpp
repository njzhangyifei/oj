#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int a) {
    // 1 3 5 7
    if (a < 2) {
        return false;
    }
    if (a == 2) {
        return true;
    }
    if (a % 2 == 0) {
        return false;
    }
    int i;
    for (i = 3; (i*i) <= a; i+=2) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> num_prime;

int brick_count[40+1];
void solve(int N) {
    memset(brick_count, 0, sizeof(int) * (40+1));
    int brick_width[2] = {4, 1};
    int brick_type = 2;
    
    brick_count[0] = 1;
    brick_count[1] = 1;
    brick_count[2] = 1;
    brick_count[3] = 1;
    brick_count[4] = 2;

    int i, j;
    // for (i = 0; i < brick_type; ++i) {
        for (j = 5; j <= N; ++j) {
            // int remain = j - brick_width[i];
            // int remain = j - brick_width[i];
            int remain = j - 1;
            if (remain >= 0) {
                // cout << "brick width = " << brick_width[i]
                    // <<" remain = " << remain << endl;
                brick_count[j] += brick_count[remain];
            }
            remain = j - 4;
            if (remain >= 0) {
                // cout << "brick width = " << brick_width[i]
                    // <<" remain = " << remain << endl;
                brick_count[j] += brick_count[remain];
            }
        }
    // }

    // for (i = 0; i < N; ++i) {
        // cout << " i =" << i << " -> " << brick_count[i] << endl;
    // }
    // cout << brick_count[N] << endl;
    // return;

    int res = 0;
    if (brick_count[N] >= num_prime.size()) {
        for (i = num_prime.size(); i <= brick_count[N]; ++i) {
            if (is_prime(i)) {
                // this is a prime
                num_prime.push_back(num_prime[i-1] + 1);
            } else {
                num_prime.push_back(num_prime[i-1]);
            }
        }
    } 
    // elsewise we don't need to calculate
    res = num_prime[brick_count[N]];

    cout << res << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    num_prime.push_back(0); // 0 primes <= 0
    num_prime.push_back(0); // 0 primes <= 1
    num_prime.push_back(1); // 1 primes <= 2
    num_prime.push_back(2); // 2 primes <= 3

    int T, N;
    cin >> T;
    int i;
    // solve(31);
    // return 0;
    for (i = 0; i < T; ++i) {
        cin >> N;
        solve(N);
    }

    return 0;
}

