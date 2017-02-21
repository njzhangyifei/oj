#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <iterator>
#include <iostream>
#include <algorithm>

#define DEBUG

using namespace std;

void longest_common_subsequence_small
(vector<int> & a, vector<int> & b, vector<int> & out) {
    int n = a.size();
    int m = b.size();
    int max_nm = max(n,m);
    int min_nm = min(n,m);

    int i, j;

    vector<int> longer = (max_nm == n) ? a : b;
    vector<int> shorter = (min_nm == n) ? a : b;
    
    int longest[max_nm];
    int new_longest[max_nm];
    int longest_prev = 0;
    memset(longest, 0, max_nm * sizeof(int));

    for (j = 0; j < min_nm; ++j) {
        for (i = 0; i < max_nm; ++i) {
            // we store longest[i-1][j] and longest[i-1][j-1] in longest[j]
            if (i == 0 && j == 0) {
                new_longest[i] = (longer[i] == shorter[j]) ? 1 : 0;
                longest_prev = new_longest[i];
                continue;
            }
            if (i == 0) {
                // j != 0
                new_longest[i] = (longer[i] == shorter[j]) ? 1 : longest[i];
                longest_prev = new_longest[i];
                continue;
            }
            if (j == 0) {
                new_longest[i] = (longer[i] == shorter[j]) ? 1 : longest_prev;
                longest_prev = new_longest[i];
                continue;
            }
            if (longer[i] == shorter[j]) {
                new_longest[i] = longest[i-1] + 1;
                longest_prev = new_longest[i];
            } else {
                new_longest[i] = max(longest[i], longest_prev);
                longest_prev = new_longest[i];
            }
        }
        if (j == min_nm - 1) {
            continue;
        }
        for (i = 0; i < max_nm; ++i) {
            longest[i] = new_longest[i];
        }
    }
    #ifdef DEBUG
    cout << "longest:" << endl;
    for (i = 0; i < max_nm; ++i) {
        cout << longest[i] << " ";
    }
    cout << endl;
    cout << "new_longest:" << endl;
    for (i = 0; i < max_nm; ++i) {
        cout << new_longest[i] << " ";
    }
    cout << endl;
    #endif
}

void longest_common_subsequence
(vector<int> & a, vector<int> & b, vector<int> & out) {
    int n = a.size();
    int m = b.size();

    uint16_t longest[n][m];
    memset(longest, 0, n * m * sizeof(uint16_t));

    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                longest[0][0] = (a[0] == b[0]) ? 1 : 0;
                continue;
            }
            if (i == 0) {
                // j != 0
                longest[i][j] = (a[i]==b[j]) ? 1 : longest[i][j-1];
                continue;
            }
            if (j == 0) {
                // i != 0
                longest[i][j] = (a[i]==b[j]) ? 1 : longest[i-1][j];
                continue;
            }
            if (a[i] == b[j]) {
                longest[i][j] = longest[i-1][j-1] + 1;
            } else {
                longest[i][j] = max(longest[i-1][j], longest[i][j-1]);
            }
        }   
    }

    int length = longest[n-1][m-1];
    i = n-1; j = m-1;
    while (length) {
        if (a[i] == b[j]) {
            // this is part of the seq
            out.insert(out.begin(), a[i]);
            i --; j --;
            length --;
            continue;
        }
        int temp = 0;
        if (i == 0) {
            temp = longest[i][j-1];
        } else if (j == 0) {
            temp = longest[i-1][j];
        } else {
            temp = max(longest[i-1][j], longest[i][j-1]);
        }
        if (temp == longest[i-1][j]) {
            i --;
        } else {
            j --;
        }
    }
    
    #ifdef DEBUG
    cout << "dp table:" << endl;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            cout << longest[i][j] << " ";
        }
        cout << endl;
    }
    cout << "LCS length:" << endl;
    cout << longest[n-1][m-1] << endl;
    #endif
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N, M;
    cin >> N >> M;

    int i, x;
    std::vector<int> a;
    std::vector<int> b;

    for (i = 0; i < N; ++i) {
        cin >> x;
        a.push_back(x);
    }

    for (i = 0; i < M; ++i) {
        cin >> x;
        b.push_back(x);
    }

    std::vector<int> v;
    // longest_common_subsequence(a, b, v);
    longest_common_subsequence_small(a, b, v);

    ostream_iterator<int> os(cout, " ");
    copy(v.begin(), v.end(), os);

    return 0;
}

