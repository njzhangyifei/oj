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
        vector<vector<int>> threeSum(vector<int>& nums) {
            if (nums.size() < 3) {
                return vector<vector<int>>();
            }
            std::sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            for (int i = 0; i < nums.size(); ++i) {
                if (i >= 1 && nums[i-1] == nums[i]) {
                    continue;
                }
                if (nums[i] <= 0 ) { 
                    cerr << "doing for " << nums[i] << endl;
                    auto s = twoSum(-nums[i], nums, i+1, nums.size());
                    for (int j = 0; j < s.size(); ++j) {
                        s[j].push_back(nums[i]);
                        std::sort(s[j].begin(), s[j].end());
                        ans.push_back(s[j]);
                        // cerr << s[rjllu0] << "+" << num[t] << "=" << target << endl;
                    }
                } else {
                    break;
                }
            }
            return ans;
        }

        static vector<vector<int>> twoSum(int target, vector<int> & num, int begin, int end){
            std::unordered_map<int,  int> diff;
            for (int i = begin; i < end; ++i) {
                diff[target - num[i]] = i;
            }
            std::vector<vector<int>> v;
            for (int i = begin; i < end; ++i) {
                if (i >= begin+1 && num[i-1] == num[i]) {
                    continue;
                }
                if (diff.find(num[i]) != diff.end()) {
                    if (i < diff[num[i]]) {
                        v.push_back({num[i], num[diff[num[i]]]});
                        cerr << num[i] << "+" << num[diff[num[i]]] << endl;
                    }
                }
            }
            return v;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    std::vector<int> v = {-1,0,1,2,-1,-4} ;
    // std::vector<int> v = {0,0,0,0};
    Solution s;
    s.threeSum(v);
    return 0;
}

