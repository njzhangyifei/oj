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
        int trap(vector<int>& height) {
            if (height.size() == 0) {
                return 0;
            }
            int l = 0;
            int r = height.size() - 1;
            int total = 0;
            int max_left = 0;
            int max_right = 0;
            while (l < r) {
                if (height[l] <= height[r]) {
                    if (height[l] > max_left) {
                        max_left = height[l];
                    } else {
                        total += max_left - height[l];
                    }
                    l ++;
                } else {
                    if (height[r] > max_right) {
                        max_right = height[r];
                    } else {
                        total += max_right - height[r];
                    }
                    r --;
                }
            }
            cerr << total << endl;
            return total;
        };
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution s;
    vector<int> trap = {0,1,0,2,1,0,1,3,2,1,2,1};
    s.trap(trap);
    return 0;
}

