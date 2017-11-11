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
        double median(vector<int> & nums, int l, int r) {
            if (r - l == 1) {
                return nums[l];
            }
            if (r - l == 2) {
                return ((double)nums[l] + (double)nums[r]) / (double)2.0;
            }
            int mid = (l + r) / 2;
            // 0 1 2 3 4
            // 0 1 2 3, l = 0, r = 4
            // 0 1 2 3 4 5, l = 0, r = 6
            if ((l+r) % 2) {
                return nums[mid];
            } else {
                return ((double)nums[mid-1] + (double)nums[mid]) / (double)2.0;
            }
        }

        double solve(
                vector<int> & n1, vector<int> & n2,
                int n1_l, int n1_r,
                int n2_l, int n2_r)
        {
            if (n1_l >= n1_r) {
                
            }
            double median_n1 = median(n1, n1_l, n1_r);
            double median_n2 = median(n2, n2_l, n2_r);
        }

        double findMedianSortedArrays(
                vector<int>& nums1, 
                vector<int>& nums2
                ) {
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

