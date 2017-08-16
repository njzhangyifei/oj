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

// deque solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> m;
        deque<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && nums[i] >= nums[s.back()]) {
                s.pop_back();
            }
            s.push_back(i);
            if (i >= k-1) {
                m.push_back(nums[s.front()]);
            }
            if (s.front() <= i-k+1) {
                s.pop_front();
            }
        }
        return m;
    }
};


// multiset solution
// class Solution {
// public:
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> m;
        // multiset<int> s;
        // for (int i = 0; i < nums.size(); ++i) {
            // s.insert(nums[i]);
            // if (i >= k) {
                // auto it = s.find(nums[i-k]);
                // s.erase(it);
            // }
            // if (s.size() >= k) {
                // m.push_back(*prev(s.end()));
            // }
        // }
        // return m;
    // }
// };

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution s;
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    int k= 3;
    vector<int> out = s.maxSlidingWindow(input, k);
    for (auto i : out) {
        cerr << i << endl;
    }
    return 0;
}

