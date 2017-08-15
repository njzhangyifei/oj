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
        vector<string> summaryRanges(vector<int>& nums) {
            int prev = nums[0];
            int start = nums[0];
            vector<string> ans;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] == prev + 1) {
                    // cont.
                    prev = nums[i];
                } else {
                    // non cont.
                    if (prev > start) {
                        // end
                        ans.push_back(to_string(start) + "->" + to_string(prev));
                    } else {
                        ans.push_back(to_string(start));
                    }
                    prev = nums[i];
                    start = nums[i];
                }
            }
            if (prev > start) {
                // end
                ans.push_back(to_string(start) + "->" + to_string(prev));
            } else {
                ans.push_back(to_string(start));
            }
            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

