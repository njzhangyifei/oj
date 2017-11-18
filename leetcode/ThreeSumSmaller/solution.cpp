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
        int threeSumSmaller(vector<int>& nums, int target) {
            if (nums.size() < 3) {
                return 0;
            }
            sort(nums.begin(),nums.end());
            if (nums[0] > target) {
                return 0;
            }
            
            int count = 0;
            for (int i = 0; i < nums.size() - 2; ++i) {
                int actual_target = target - nums[i];
                int lo = i+1;
                int hi = nums.size() - 1;
                while (lo < hi) {
                    if (nums[lo] + nums[hi] > actual_target) {
                        // too larget
                        hi --;
                    } else {
                        lo ++;
                        count += hi - lo;
                    }
                }
            }
            return count;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

