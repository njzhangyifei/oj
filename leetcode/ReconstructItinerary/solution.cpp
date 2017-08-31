#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <stack>
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
        vector<string> findItinerary(vector<pair<string, string>> tickets) {
            std::unordered_map<string, multiset<string>> adj;
            for (int i = 0; i < tickets.size(); ++i) {
                adj[tickets[i].first].insert(tickets[i].second);
            }
            std::vector<string> v;
            std::stack<string> s;
            s.push("JFK");
            while (s.size()) {
                string curr = s.top();
                if (adj[curr].size()) {
                    auto it = adj[curr].begin();
                    adj[curr].erase(it);
                    s.push(*it);
                } else {
                    v.push_back(curr);
                    s.pop();
                }
            }
            std::reverse(v.begin(), v.end());
            return v;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

