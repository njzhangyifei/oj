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
        vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            std::vector<int> sorted_nums_1;
            std::vector<int> sorted_nums_2;
            for (int i = 0; i < k; ++i) {
                if (i < nums1.size()) {
                    sorted_nums_1.push_back(nums1[i]);
                }
                if (i < nums2.size()) {
                    sorted_nums_2.push_back(nums2[i]);
                }
            }
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            std::priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> v;

            for (int i = 0; i < sorted_nums_1.size(); ++i) {
                for (int j = 0; j < sorted_nums_2.size(); ++j) {
                    v.push(make_tuple(
                                sorted_nums_1[i] + sorted_nums_2[j],
                                sorted_nums_1[i], sorted_nums_2[j])
                            );
                }
            }

            std::vector<pair<int, int>> ans;
            for (int i = 0; i < min(k, (int)(sorted_nums_1.size() * sorted_nums_2.size())); ++i) {
                tuple<int, int, int> t = v.top();
                ans.push_back(make_pair( get<1>(t), get<2>(t)));
            }

            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

