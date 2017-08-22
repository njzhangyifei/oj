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


class Solution {
    public:
        int longestPalindrome(string s) {
            std::unordered_map<char, int> m;
            for (size_t i = 0; i < s.size(); ++i) {
                m[s[i]] ++;
            }
            int total = 0;
            int offset = 0;
            for (auto i : m) {
                if (i.second  % 2 == 0) {
                    total += i.second;
                } else {
                    total += i.second -1;
                    offset = 1;
                }
            }
            return total + offset;
        }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

