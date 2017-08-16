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
#include <unordered_set>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int64_t> m;
        for (size_t i = 0; i < s.size(); ++i) {
            m[s[i]]++;
        }
        for (size_t i = 0; i < t.size(); ++i) {
            m[t[i]]--;
        }
        for (auto i : m) {
            if (i.second < 0) {
                return i.first;
            }
        }
        return 0;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

