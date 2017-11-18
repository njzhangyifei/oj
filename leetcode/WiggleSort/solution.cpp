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
        void wiggleSort(vector<int>& nums) {
            for (int i = 1; i < nums.size(); ++i) {
                if ((i % 2 == 0 && nums[i-1] < nums[i]) ||
                    (i % 2 == 1 && nums[i-1] > nums[i])
                    ) {
                    swap(nums[i-1], nums[i]);
                }
            }
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

