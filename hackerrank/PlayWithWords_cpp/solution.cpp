#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int solve(string& s){
    int len = s.length();
    int i, j;
    int ** subseq = new int * [len];
    for (i = 0; i < len; ++i) {
        subseq[i] = new int[len];
        memset(subseq[i], 0, len * sizeof(int));
    }

    for (i = 0; i < len; ++i) {
        subseq[i][i] = 1;
    }

    for (i = 2; i <= len; ++i) {
        for (j = 0; j < len-i+1; ++j) {
            int end = j + i - 1;
            if (s[j] == s[end] && i == 2) {
                subseq[j][end] = 2;
            } else if (s[j] == s[end]) {
                subseq[j][end] = subseq[j+1][end-1] + 2;
            } else {
                subseq[j][end] = max(subseq[j+1][end], subseq[j][end-1]);
            }
        }
    }

    int max_score = 0;
    for (i = 1; i <= len-1; ++i) {
        int first_start = 0;
        int first_end = i-1;
        int second_start = i;
        int second_end = len-1;
        int score = subseq[first_start][first_end] * subseq[second_start][second_end];
        max_score = max(max_score, score);
    }

    return max_score;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}

