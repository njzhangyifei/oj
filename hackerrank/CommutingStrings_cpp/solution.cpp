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

#define MOD_1E9_7 (1000000007)
using namespace std;



int solve(string s, int M) {
    int s_len = s.length();
    int reapeat_len = s_len;
    int i, j;
    if (s_len == 1) {
        reapeat_len = 1;
    }
    for (i = 1; i < (s_len / 2)+1; ++i) {
        if (s_len % i != 0) {
            continue;
        }
        bool repeat = true;
        for (j = i; j < s_len; j += i) {
            // check for each starting index
            if (s.compare(0, i, s, j, i) != 0) {
                repeat = false;
            }
        }

        if (repeat) {
            reapeat_len = i;
            break;
        }
    }

    cerr << reapeat_len << endl;
    return (M / reapeat_len) % MOD_1E9_7;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    string s;
    int M;

    cin >> s;
    cin >> M;

    int ans = solve(s, M);

    cout << ans << endl;

    return 0;
}

