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
        int longest(string s) {
            size_t max = 0;
            size_t start=0;
            size_t end=0;

            std::map<char, pair<size_t, size_t>> last;
            for (size_t i = 0; i < s.length(); ++i) {
                char ch = s[i];
                int block_s = i;
                while (i < s.length()-1 && s[i+1] == ch) {
                    i++;
                    // cont. block
                }
                int block_e = i;
                // cerr << "blocks=" << block_s << " block_e=" << block_e << endl;
                end = i;
                if (last.find(ch) != last.end() || last.size() <= 1) {
                    // found
                    last[ch] = make_pair(block_s, block_e);
                    // cerr << start << ", " << end << endl;
                    max = std::max(max, end-start+1);
                } else {
                    // get prev char
                    // cerr << ">3" << endl;
                    char prev = s[block_s-1];
                    char toremove;
                    for (auto i : last) {
                       if (i.first != prev) {
                           toremove = i.first;
                       } 
                    }
                    last.erase(toremove);
                    start = last[prev].first;
                    last[ch] = make_pair(block_s, block_e);
                    // cerr << prev << start << ", " << end << endl;
                    max = std::max(max, end-start+1);
                }
            }
            return (int)max;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution s;
    cerr << s.longest("baabcddeee") << endl;
    return 0;
}

