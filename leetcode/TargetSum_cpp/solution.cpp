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
        int findTargetSumWays(vector<int>& nums, int S) {
            if (nums.size() == 0) {
                if (S == 0) {
                    return true;
                } else {
                    return false;
                }
            }

            unordered_map<int, int> map;
            map[nums[0]] += 1;
            map[-nums[0]] += 1;

            for (int i = 1; i < nums.size(); ++i) {
                unordered_map<int, int> next_map;
                for (auto j : map) {
                    next_map[j.first-nums[i]] += j.second;
                    next_map[j.first+nums[i]] += j.second;
                }
                map = next_map;
            }

            return map[S];
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution s;
    vector<int> v = {1, 1, 1, 1, 1};
    cout << s.findTargetSumWays(v, 3) << endl;
    vector<int> v_1 = {0,0,0,0,0,0,0,0,1};
    cout << s.findTargetSumWays(v_1, 1) << endl;
    return 0;
}

