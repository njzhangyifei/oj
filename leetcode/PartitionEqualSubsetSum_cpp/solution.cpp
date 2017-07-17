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
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i];
            }

            if (nums.size() == 1 && sum != 0) {
                return false;
            }

            if (sum % 2 != 0) {
                return false;
            }

            int target = sum / 2;
            bool map[target + 1];

            for (int i = 0; i <= target; ++i) {
                map[i] = false;
            }

            for (int i = 0; i < nums.size(); ++i) {
                for (int j = target; j >= 0; j --) {
                    if ((j - nums[i] >=0) && map[j - nums[i]]) {
                        map[j] = true;
                    }
                    cout << map[j] << " ";
                }
                cout << endl;
                if (nums[i] <= target) {
                    map[nums[i]] = true;
                }
            }

            return map[target];
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution s;
    // std::vector<int> v = { 2, 2, 4, 5 };
    // cout << s.canPartition(v) << endl;
    std::vector<int> v_1= { 1, 2, 5 };
    cout << s.canPartition(v_1) << endl;
    return 0;
}

