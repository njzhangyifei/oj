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
        int hIndex(vector<int>& citations) {
            std::map<int, int> m;
            for (size_t i = 0; i < citations.size(); ++i) {
                m[citations[i]] ++;
            }

            int total = citations.size();
            int ans = 0;
            int below = 0;
            for (int i = 0; i <= total; ++i) {
                if (i <= (total - below)) {
                    ans = i;
                }

                if (m.find(i) != m.end()) {
                    below += m[i];
                }
            }

            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

