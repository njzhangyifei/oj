#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

// #define DEBUG

#define MOD_NUM 1000000007

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    string s;
    cin >> s;

    int len = s.length();

    /* extract digits */
    uint8_t digit[len];
    int i, j;
    for (i = 0; i < len; ++i) {
        digit[i] = s[i] - '0';
    }

#ifdef DEBUG
    cout << "digits:" << endl;
    for (i = 0; i < len; ++i) {
        cout << (int)digit[i] << " ";
    }
    cout << endl;
#endif

    int sum[len + 1];
    memset(sum, 0, sizeof(int) * (len+1));

    //////////////////////////////
    // dp by using information about 0-9
    //////////////////////////////
    int digit_sum[10];
    memset(digit_sum, 0, sizeof(int) * 10);

    int pos_factor[len];
    pos_factor[len-1] = 1;
    for (i = len - 2; i >= 0; --i) {
        pos_factor[i] = ((uint64_t)pos_factor[i+1] * 10 + 1) % MOD_NUM;
    }

    for (i = 0; i < len; ++i) {
        pos_factor[i] = ((uint64_t)pos_factor[i] * (i+1)) % MOD_NUM;
    }

    for (i = 0; i < len; ++i) {
        uint64_t temp = ((uint64_t)pos_factor[i] * digit[i]) % MOD_NUM;
        digit_sum[digit[i]] = (digit_sum[digit[i]] + temp) % MOD_NUM;
    }

#ifdef DEBUG
    cout << "pos_factor:" << endl;
    for (i = 0; i < len; ++i) {
        cout << "[" << i << "] " << pos_factor[i] << endl;
    }

    cout << "digit_sum" << endl;
    for (i = 0; i < 10; ++i) {
        cout << "[" << i << "] " << digit_sum[i] << endl;
    }
#endif

    //////////////////////////////
    // dp by dynamically allocating mem => tooooo slow ( O(n^2) )
    //////////////////////////////
    // int ** num_table = (int **)malloc((len+1) * (sizeof(int *)));
    // for (i = 0; i < 2; ++i) {
        // num_table[i] = (int *)malloc((len) * sizeof(int));
        // for (j = 0; j < len; ++j) {
            // num_table[i][j] = -1;
        // }
    // }

    // for (i = 0; i < len; ++i) {
        // num_table[0][i] = 0;
        // num_table[1][i] = digit[i];
        // sum[1] = (sum[1] + (num_table[1][i] % MOD_NUM)) % MOD_NUM;
    // }

    // for (i = 2; i <= len; ++i) {
        // num_table[i] = (int *)malloc((len) * sizeof(int));
        // for (j = 0; j < len; ++j) {
            // num_table[i][j] = -1;
        // }
        // uint64_t num = 0;
        // // cout << "Generating length " << i << endl;
        // for (j = 0; (j+i) <= len; ++j) {
            // // generate the number using previous data
            // //   start with j and length is i, ends with [i+j-1]
            // num = digit[i+j-1];
            // num += 10 * (uint64_t)num_table[i-1][j];
            // num %= MOD_NUM;
            // num_table[i][j] = num;
            // sum[i] = (sum[i] + (num % MOD_NUM)) % MOD_NUM;
        // }
        // free(num_table[i-1]);
    // }

    //////////////////////////////
    // Brute-force
    //////////////////////////////
    // // for all length
    // for (i = 1; i <= len; ++i) {
        // cout << "Running length " << i << endl;
        // // for all start,
        // for (j = 0; (j+i) <= len; j++) {
            // // generate the number with length i, and starts with j
            // int k;
            // uint64_t num = digit[j];
            // for (k = 1; k < i; ++k) {
                // num *= 10;
                // num += digit[j+k];
                // num %= MOD_NUM;
            // }
            // sum[i] = (sum[i] + (num % MOD_NUM)) % MOD_NUM;
        // }
    // }

// #ifdef DEBUG
    // cout << "sums:" << endl;
    // for (i = 0; i < len+1; ++i) {
        // cout << sum[i] << " ";
    // }
    // cout << endl;
// #endif

    unsigned int result = 0;
    // for (i = 0; i < len+1; ++i) {
        // result = (result + sum[i]) % MOD_NUM;
    // }
    for (i = 0; i < 10; ++i) {
        result = (result + digit_sum[i]) % MOD_NUM;
    }
    cout << result << endl;

    return 0;
}

