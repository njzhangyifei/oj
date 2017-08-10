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
    int numSquares(int n) {
        std::vector<int> v;
        for (int i = 1; i * i <= n; ++i) {
            v.push_back(i*i);
        }
        std::reverse(v.begin(), v.end());

        cerr << "sqs: ";
        for (auto i : v) {
            cerr << i << " ";
        }
        cerr << endl;

        int map[n+1];
        for (int i = 0; i < n+1; ++i) {
            map[i] = -1;
        }
        
        for (int i = 0; i < v.size(); ++i) {
            map[v[i]] = 1;
        }

        for (int i = 0; i < n+1; ++i) {
            for (int j = 0; j < v.size(); ++j) {
                if (i - v[j] >= 0 && map[i-v[j]] != -1) {
                    // possible
                    if (map[i] == -1) {
                        map[i] = INT_MAX;
                    }
                    map[i] = min(map[i], map[i-v[j]] + 1);
                }
            }
            // for (int k = 0; k < n+1; ++k) {
                // cerr << map[k] << " ";
            // }
            // cerr << endl;
        }

        return map[n];
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    Solution s;
    // for (int i = 10; i < 50; i+=3) {
        // cerr << i << " -> " << s.numSquares(i) << endl;
    // }
    cerr << s.numSquares(43) << endl;
    // cerr << s.numSquares(12);
    return 0;
}

