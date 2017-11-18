#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstringTwoDistinct(string s) {
            int left = 0;
            int right = left;
            unordered_map<char, int> map;
            int longest = 0;

            while (left <= s.size()-1 & right < s.size()) {
                char ch = s[right ++];
                if (map.size() < 2 || map.find(ch) != map.end()) {
                    map[ch] = right;
                    longest = max(longest, right - left);
                } else {
                    int toremove = s.size() -1;
                    for (auto i : map) {
                        toremove = min(toremove, i.second);
                    }
                    map.erase(s[toremove-1]);
                    left= toremove;
                    right = left;
                }
            }

            return longest;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

