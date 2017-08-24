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
        int countRangeSum(vector<int>& nums, int lower, int upper) {
            std::multiset<int> m;

            int ans = 0;
            int sum = 0;
            m.insert(sum);
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i];
                ans += std::distance( m.lower_bound(sum-upper), m.upper_bound(sum-lower));
                m.insert(sum);
            }
            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

