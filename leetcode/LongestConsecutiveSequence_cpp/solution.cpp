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
        int longestConsecutive(vector<int>& nums) {
            if (nums.size() == 0) {
                return 0;
            }
            std::unordered_set<int> s(nums.begin(), nums.end());
            int res = 1;
            for (auto i : nums) {
                if (s.find(i) == s.end()) {
                    continue;
                }
                s.erase(i);
                int next = i + 1;
                int prev = i - 1;
                while (s.find(next) != s.end()) {
                    s.erase(next++);
                }
                while (s.find(prev) != s.end()) {
                    s.erase(prev--);
                }
                res = max(res, next-prev-1);
            }
            return res;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

