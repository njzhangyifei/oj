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

void solve(int S, string & P, string & Q) {
    int i, j, k;

#ifdef DEBUG
    cout << "input:" << endl;
    cout << " | S: " << S << endl;
    cout << " | P: " << P << endl;
    cout << " | Q: " << Q << endl;
#endif

    int str_len = P.length();

    uint8_t diff_table[str_len][str_len];

    for (i = 0; i < str_len; ++i) {
        for (j = 0; j < str_len; ++j) {
            diff_table[i][j] = (P[i] != Q[j]);
        }
    }

    int end_index = 0;
    int max_len = 0;
    
    // for all offset possible
    for (i = 0; i < str_len; ++i) {
        int start_sum_p = 0;
        int start_sum_q = 0;
        int end_sum_p = 0;
        int end_sum_q = 0;
        int start_index_p = 0;
        int start_index_q = 0;
        for (end_index = 0; (end_index + i) < str_len; ++end_index) {
            // sum up the number of mismatch if we shift string Q
            end_sum_q += diff_table[end_index][i+end_index];
            // sum up the number of mismatch if we shift string P
            end_sum_p += diff_table[i+end_index][end_index];
            
            // we move the pointer for start in q, until mismatch < S
            while (end_sum_q - start_sum_q > S) {
                start_sum_q += diff_table[start_index_q][i+start_index_q];
                start_index_q++;
            }

            // we move the pointer for start in p, until mismatch < S
            while (end_sum_p - start_sum_p > S) {
                start_sum_p += diff_table[i+start_index_p][start_index_p];
                start_index_p++;
            }

            // update the longest mismatch for each possible shifting method
            if (end_index - start_index_p > max_len) {
                max_len = end_index - start_index_p;
            }
            if (end_index - start_index_q > max_len) {
                max_len = end_index - start_index_q;
            }

#ifdef DEBUG
            cout << "[i] = " << i << endl;
            cout << " | end_index = " << end_index << endl;
            cout << " | start_index_p = " << start_index_p <<
                ", start_index_q = " << start_index_q << endl;
            cout << " | start_sum_p = " << start_sum_p <<
                ", start_sum_q = " << start_sum_q << endl;
            cout << " | end_sum_p = " << end_sum_p <<
                ", end_sum_q = " << end_sum_q << endl;
#endif
        }
    }

#ifdef DEBUG
    cout << "diff_table:" << endl;
    for (i = 0; i < str_len; ++i) {
        for (j = 0; j < str_len; ++j) {
            cout << (unsigned int)diff_table[i][j] << " ";
        }
        cout << endl;
    }
#endif

#ifdef DEBUG
    cout << "max_len:" << endl;
#endif
    cout << max_len + 1 << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;

    int i;
    for (i = 0; i < T; ++i) {
        int S;
        string P, Q;
        cin >> S >> P >> Q;
        solve(S, P, Q);
    }
    return 0;
}

