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
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int> & l, const pair<int, int> & r) {
            if (l.first < r.first) {
                return true;
            } else {
                if (l.first == r.first) {
                    return l.second > r.second;
                }
            }
            return false;
        };

        std::priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(comp)> 
            ppl (comp, people);

        std::vector<pair<int, int>> res;
        for (int i = 0; i < people.size(); ++i) {
            auto p = ppl.top();
            ppl.pop();
            res.insert(res.begin() + p.second, p);
        }

        return res;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

