#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

string * solve(string& s){
    string * longest = new string();
    int len = s.length();
    int i, j;
    uint8_t ** map = new uint8_t * [len];

    int max_len = 0;
    int max_start = 0;
    for (i = 0; i < len; ++i) {
        map[i] = new uint8_t[len];
        memset(map[i], 0, sizeof(uint8_t) * len);
    }

    for (i = 0; i < len; ++i) {
        map[i][i] = 1;
        max_len = 1;
    }

    for (i = 0; i < len-1; ++i) {
        if (s[i] == s[i+1]) {
            if (2 > max_len) {
                max_len = max(max_len, 2);
                max_start = i;
            }
            map[i][i+1] = 1;
        }
    }

    for (i = 3; i <= len; i++) {
        for (j = 0; j < len - i +1; ++j) {
            int end = i + j - 1;
            if (map[j+1][end-1] && s[j] == s[end]) {
                map[j][end] = 1;
                if (i > max_len) {
                    max_len = max(max_len, i);
                    max_start = j;
                }
            }
        }
    }

    *longest = s.substr(max_start, max_len);

    for (i = 0; i < len; ++i) {
        delete map[i];
    }
    delete map;

    return longest;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    
    int i;
    for (i = 0; i < T; ++i) {
        string s;
        cin >> s;
        string * result = solve(s);
        cout << *result << endl;
        delete result;
    }
    return 0;
}

