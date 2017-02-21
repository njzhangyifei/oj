#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

// #define DEBUG

int bin_search_lower(int table[], int target, int size) {
    int left = -1, right = size-1;
    while (right - left > 1) {
        int index = left + (right - left) / 2;
        if (table[index] >= target) {
            // on the left side
            right = index;
        } else {
            // on the right side
            left = index;
        }
    }
    return right;
}

void print_array(int n[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        cout << n[i] << " " ;
    }
    cout << endl;
}

void solve_LIS(int N, int num[]) {
    int * last_num_table = new int[N];
    memset(last_num_table, 0, sizeof(int)*N);

    int max_len = 1;
    last_num_table[0] = num[0];

    int i ;
    for (i = 1; i < N; ++i) {
        if (num[i] < last_num_table[0]) {
            last_num_table[0] = num[i];
        } else if (num[i] > last_num_table[max_len-1]) {
            // larger than the last num of the longest seq
            last_num_table[max_len++] = num[i];
        } else {
            // bin search
            int index = bin_search_lower(last_num_table, num[i], max_len);
            last_num_table[index] = num[i];
        }
    }

#ifdef DEBUG
    cout << "last_num_table:" << endl;
    print_array(last_num_table, N);
#endif

    cout << max_len;
}

// this method is tooo slow (n ^ 2)
void solve_LIS_slow(int N, int num[]) {
    int i, j;
    // int v[N][2];
    // memset(v, 0, sizeof(int) * (N * 2));
    int ** v = (int **)malloc(sizeof(int *) * N);
    for (i = 0; i < N; ++i) {
        v[i] = (int *)malloc(sizeof(int) * 2);
        v[i][0] = 0;
        v[i][1] = 0;
    }

    v[0][0] = 1;
    v[0][1] = num[0];
    // v[i] => longest increasing subseq that ends at num[i]
    for (i = 1; i < N; ++i) {
        for (j = i-1; j >= 0; --j) {
            if (v[j][1] < num[i] && v[j][0] > v[i][0]) {
                v[i][0] = v[j][0];
                v[i][1] = v[j][1];
            }
        }
        v[i][0] = v[i][0] + 1;  // size
        v[i][1] = num[i]; // last
    }

#ifdef DEBUG
    cout << "v:" << endl;
    for (i = 0; i < N; ++i) {
        cout << "[" << i << "]";
        for (j = 0; j < 2; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
#endif

    int max_len = 0;
    for (i = 0; i < N; ++i) {
        max_len = max(max_len, v[i][0]);
    }

    cout << max_len << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    
    int i;
    int * num = new int[N];
    for (i = 0; i < N; ++i) {
        cin >> num[i];
    }

#ifdef DEBUG
    cout << "INPUT:" << endl;
    for (i = 0; i < N; ++i) {
        cout << num[i] << " ";
    }
    cout << endl;
#endif

    solve_LIS(N, num);

    return 0;
}

