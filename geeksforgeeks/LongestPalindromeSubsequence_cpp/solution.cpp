#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(string& s){
    string * longest = new string();
    int len = s.length();
    int L[len][len];

    int i, j;
    for (i = 0; i < len; ++i) {
        L[i][i] = 1;
    }

    for (i = 2; i <= len; ++i) {
        for (j = 0; j < len-i+1; ++j) {
            int end = i+j-1;
            if (s[j] == s[end] && i == 2) {
                L[j][end] = 2;
            } else if (s[j] == s[end]) {
                L[j][end] = L[j+1][i-1] + 2;
            } else {
                L[j][end] = max(L[j][end-1], L[j+1][end]);
            }
        }
    }
    int max_len = L[0][len-1];
    return max_len;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    
    int i;
    for (i = 0; i < T; ++i) {
        string s;
        cin >> s;
        int len_subseq = solve(s);
        cout << len_subseq << endl;
    }
    return 0;
}

