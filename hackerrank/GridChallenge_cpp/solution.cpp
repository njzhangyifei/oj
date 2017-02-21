#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

bool solve(int N, char ** data){
    bool swapped = false;
    int i, j;
    for (i = 0; i < N; ++i) {
        do {
            swapped = false;
            for (j = 1; j < N; ++j) {
                if (data[i][j-1] < data[i][j]) {
                    char temp = data[i][j-1];
                    data[i][j-1] = data[i][j];
                    data[i][j] = temp;
                    swapped = true;
                }
            }
        } while (swapped);
    }

    // check each column
    for (i = 0; i < N; ++i) {
        for (j = 1; j < N; ++j) {
            if (data[j-1][i] > data[j][i] ) {
                return false;
            }
        }
    }
    

    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N;
    cin >> T;

    int i;
    for (i = 0; i < T; ++i) {
        cin >> N;
        int j;
        char ** data = new char * [N];
        for (j = 0; j < N; ++j) {
            data[j] = new char[N];
        }
        for (j = 0; j < N; ++j) {
            string s;
            cin >> s;
            int k;
            for (k = 0; k < N; ++k) {
                data[j][k] = s[k];
            }
        }
        bool res = solve(N, data);
        cout << (res ? "YES" : "NO") << endl;
        for (j = 0; j < N; ++j) {
            delete data[j];
        }
        delete data;
    }
    return 0;
}

