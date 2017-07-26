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
        vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
            priority_queue<
                pair<int, int>,
                std::vector<pair<int, int>>,
                std::less<pair<int, int>>
                > pp;
            for (auto i : people) {
                pp.push(make_pair(i.first, -i.second));
            }

            std::vector<pair<int, int>> q;
            while (pp.size()) {
                auto p = pp.top();
                pp.pop();
                // cerr << p.first << " - " << p.second << endl;
                q.insert( q.begin() - p.second, make_pair(p.first, -p.second));
            }

            return q;
        }
};



int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT   
    //
    Solution s;
    vector<pair<int, int>> v = {{8,2},{4,1},{0,3},{3,2},{8,1},{4,0},{7,0},{6,2},{8,0},{4,7}};

    auto res = s.reconstructQueue(v);
    for (int i = 0; i < res.size(); ++i) {
        cout << "(" << res[i].first << "," << res[i].second << ") ";
    }
    return 0;
}

