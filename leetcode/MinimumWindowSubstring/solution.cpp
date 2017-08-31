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
        string minWindow(string s, string t) {
            if (t.size() == 0 || s.size() == 0) {
                return "";
            }
            unordered_map<char, int> map;
            for (auto i : t) {
                map[i]--;
            }
            int len = INT_MAX;
            string ans = "";
            int i = 0;
            int j = 0;
            bool cover = false;
            while (i < s.size() && j < s.size()) { 
                if (map.find(s[j]) != map.end()) {
                    // found
                    map[s[j]] ++;
                }

                if (! cover) {
                    cover = true;
                    for (auto i : map) { 
                        cover &= i.second >= 0; 
                    }
                }

                if (cover) {
                    while ((j-i+1) >= t.size()) {
                        if (map.find(s[i]) != map.end()) {
                            if (map[s[i]] == 0) {
                                break;
                            }
                            map[s[i]] --;
                        }
                        i++;
                    }
                    if ((j-i+1) < len && (j-i+1) >= t.size()) {
                        len = j-i+1;
                        ans = s.substr(i, len);
                    }
                }
                j ++;
            }
            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

