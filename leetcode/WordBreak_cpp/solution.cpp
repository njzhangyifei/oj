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

// class Solution {
// public:
    // bool explore(string & s, int from, unordered_set<string> & dict){
        // for (int len = 0; len <= s.size() - from; ++len) {
            // string t = s.substr(from, len);
            // cerr << t << endl;
            // if (dict.find(t) == dict.end()) {
                // // not in dict
                // continue;
            // } else {
                // cerr << "found" << endl;
                // if (from + len == s.size()) {
                    // return true;
                // }
                // bool r = explore(s, from + len, dict);
                // if (r) {
                    // return true;
                // }
            // }
        // }
        // return false;
    // }

    // bool wordBreak(string s, vector<string>& wordDict) {
        // std::unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // return explore(s, 0, dict);
    // }
// };


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> m(s.size());
        std::fill(m.begin(), m.end(), false);

        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < wordDict.size(); ++j) {
                if (wordDict[j].size() + i < s.size()) {
                    
                }
            }
        }

        return false;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution s;
    string in = "leetcodeleet";
    vector<string> d = {"leet","code", "tcodeleet"};
    s.wordBreak(in, d);
    return 0;
}

