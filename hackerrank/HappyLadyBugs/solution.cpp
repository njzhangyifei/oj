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
using namespace std;


bool solve(string &s, int length){
    std::map<char, int> map;
    bool has_empty = false;
    int i;
    for (i = 0; i < s.length(); ++i) {
        char ch = s[i];
        if (ch != '_') {
            map[ch]++;
        } else {
            has_empty = true;
        }
    }
    if (has_empty) {
        for (auto it : map) {
            if (it.second == 1) {
                // not even
                return false;
            }
        }
    } else {
        for (i = 0; i < s.length(); ++i) {
            if (s[i] == '_') {
                continue;
            }
            if (i-1 < 0) {
                // no left
                if (s[i+1] != s[i]) {
                    return false;
                }
            } else if (i+1 >= s.length()){
                // no right
                if (s[i-1] != s[i]) {
                    return false;
                }
            } else {
                // either
                if (s[i-1] != s[i] && s[i+1] != s[i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;

    int i;
    for (i = 0; i < N; ++i) {
        int length;
        string s;
        cin >> length;
        cin >> s;

        bool res = solve(s, length);
        cout << (res ? "YES" : "NO") << endl;
    }

    return 0;
}

