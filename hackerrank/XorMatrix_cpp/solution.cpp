#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

#define DEBUG

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int M;
    cin >> N >> M;

    std::vector<int> v_input;
    int i, j;
    for (i = 0; i < N; ++i) {
        int t;
        cin >> t;
        v_input.push_back(t);
    }
    v_input.push_back(v_input[0]);

    std::vector<int> v_temp = v_input;

    // if (M > N*2) {
    if ( false) {
        for (i = 0; i < 2*N; ++i) {
            for (j = 0; j < N; ++j) {
                v_temp[j] = v_input[j] ^ v_input[j+1];
            }
            v_temp[N] = v_temp[0];
            v_input = v_temp;

            #ifdef DEBUG
            for (j = 0; j < N; ++j) {
                cout << v_temp[j] << " ";
            }
            cout << endl;
            #endif
        }
        for (i = 0; i < (M-2*N-1)%N; ++i) {
            for (j = 0; j < N; ++j) {
                v_temp[j] = v_input[j] ^ v_input[j+1];
            }
            v_temp[N] = v_temp[0];
            v_input = v_temp;

            #ifdef DEBUG
            for (j = 0; j < N; ++j) {
                cout << v_temp[j] << " ";
            }
            cout << endl;
            #endif

        }
    } else {
        for (i = 0; i < M-1; ++i) {
            for (j = 0; j < N; ++j) {
                v_temp[j] = v_input[j] ^ v_input[j+1];
            }
            v_temp[N] = v_temp[0];
            v_input = v_temp;

            #ifdef DEBUG
            for (j = 0; j < N; ++j) {
                cout << v_temp[j] << " ";
            }
            cout << endl;
            #endif
        }
    }

    for (j = 0; j < N; ++j) {
        cout << v_temp[j] << " ";
    }
    cout << endl;


    return 0;
}

