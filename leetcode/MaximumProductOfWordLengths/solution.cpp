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
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<bitset<26>> t;
        for (size_t i = 0; i < words.size(); ++i) {
            auto w = words[i];
            bitset<26> s (0);
            for (size_t j = 0; j < w.size(); ++j) {
                s[w[j] - 'a'] = 1;
            }
            t.push_back(s);
        }

        size_t max_len = 0;
        for (size_t i = 0; i < t.size(); ++i) {
            for (size_t j = i + 1; j < t.size(); ++j) {
                if ((t[i] ^ t[j]).count() == (t[i].count() + t[j].count())) {
                    max_len = max(max_len, words[i].length() * words[j].length());
                }
                // max_len, (t[i] ^ t[j]).count());
            }
        }

        cerr << max_len << endl;
        return max_len;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<string> input = {"eae","ea","aaf","bda","fcf","dc","ac","ce","cefde","dabae"};
    Solution s;
    s.maxProduct(input);
    return 0;
}

