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
        int maxArea(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            #define HL (height[left])
            #define HR (height[right])
            #define W (right - left)

            int current_area = 0;

            while (left != right) {
                current_area = std::max(std::min(HL, HR) * W, current_area);
                if (HL > HR) {
                    right --;
                } else {
                    left ++;
                }
            }
            cerr << current_area << endl;
            return current_area;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    Solution s;

    // vector<int> test = {1,2,3,4,5,6,7,8,9,10};
    vector<int> test = {1, 2, 4, 3};
    s.maxArea(test);

    return 0;
}

