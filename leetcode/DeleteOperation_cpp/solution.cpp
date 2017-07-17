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
        static int len_lcs(string a, string b){
            int map[a.length()+1][b.length()+1];

            int i, j;
            for (i = 0; i < a.length()+1; ++i) {
                for (j = 0; j < b.length()+1; ++j) {
                    map[i][j] = 0;
                }
            }

            for (i = 1; i < a.length()+1; ++i) {
                for (j = 1; j < b.length()+1; ++j) {
                    if (a[i-1] == b[j-1]) {
                        map[i][j] = map[i-1][j-1] + 1;
                    } else {
                        map[i][j] = max(map[i-1][j], map[i][j-1]);
                    }
                }
            }

            return map[a.length()][b.length()];
        }

        int minDistance(string word1, string word2) {
            auto len = Solution::len_lcs(word1, word2);
            cout << len;
            return (word1.length() - len)+(word2.length() - len);
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution s;
    int ans = s.minDistance("a", "ab");
    cout << ans;
    return 0;
}

