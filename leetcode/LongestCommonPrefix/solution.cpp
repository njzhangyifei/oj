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
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.size() == 0) {
                return "";
            }
            if (strs.size() == 1) {
                return strs[0];
            }
            auto s = strs;
            std::sort(s.begin(), s.end());
            size_t min_len = std::min(s.front().length(), s.back().length());
            string ss = "";
            auto f = s.front();
            auto b = s.back();
            for (size_t i = 0; i < min_len; ++i) {
                if (f[i] == b[i]) {
                    ss += f[i];
                } else {
                    break;
                }
            }
            return ss;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

