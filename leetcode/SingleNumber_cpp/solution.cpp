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
        int singleNumber(vector<int>& nums) {
            int x = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                x ^= nums[i];
            }
            return x;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

