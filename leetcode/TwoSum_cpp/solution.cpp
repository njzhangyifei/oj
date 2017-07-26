#include <cmath>
#include <cassert>
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
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> num_map;
        std::vector<int> res;
        int i;
        for (i = 0; i < nums.size(); ++i) {
            auto it = num_map.find(target-nums[i]);
            if (it != num_map.end()) {
                // has this
                int other_index = (*it).second;
                res.push_back(other_index);
                res.push_back(i);
                break;
            }
            num_map[nums[i]] = i;
        }
        return res;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> nums = {0, 4, 3, 0};
    int target = 0;
    
    vector<int> res = {0, 3};

    Solution s;
    auto r = s.twoSum(nums, target);
    cerr << "vec: ";
    for (auto i : r) {
        cerr << i << ", ";
    }
    cerr << endl;
    assert(r == res);
    cout << "PASSED" << endl;


    return 0;
}

