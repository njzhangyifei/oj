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
        int ans;
        int peak(vector<int>& nums, int from, int to) {
            if (to - from < 1) {
                return INT_MIN;
            }
            if (to - from == 1) {
                return from;
            }
            int mid = (to - from) / 2 + from;
            if (nums[mid-1] < nums[mid]) {
                // r
                return peak(nums, 0, mid);
            } else {
                return peak(nums, mid, to);
            }
        }

        int findPeakElement(vector<int>& nums) {
            return peak(nums, 0, nums.size());
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

