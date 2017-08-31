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

// class Solution {
    // public:
        // int countRangeSum(vector<int>& nums, int lower, int upper) {
            // std::multiset<int> m;

            // int ans = 0;
            // int sum = 0;
            // m.insert(sum);
            // for (int i = 0; i < nums.size(); ++i) {
                // sum += nums[i];
                // ans += std::distance( m.lower_bound(sum-upper), m.upper_bound(sum-lower));
                // m.insert(sum);
            // }
            // return ans;
        // }
// };

class Solution {
    struct node {
        int64_t l;
        int64_t r;
        int64_t count;
        node * left;
        node * right;

        node (int64_t l, int64_t r) {
            this->l = l; this->r = r; this->count = 0;
            this->left = nullptr; this->right = nullptr;
        }
    };

    void update(node * root, int64_t val){
        if (root != nullptr && root->l <= val && val <= root->r) {
            // check if in int64_terval [l, r]
            root->count++;
            update(root->left, val);
            update(root->right, val);
        }
    }

    int64_t segsum(node * root, int64_t l, int64_t r){
        if (root == nullptr || root->r < l || root->l > r) {
            return 0;
        }
        if (l <= root->l && root->r <= r) {
            // completely in int64_terval, end
            return root->count;
        } else {
            return segsum(root->left, l, r) + segsum(root->right, l, r);
        }
    }

    node * buildSegTree(vector<int64_t> & nums, int64_t l, int64_t r){
        if (l > r) {
            return nullptr;
        }
        node * n = new node(nums[l], nums[r]);
        if (l == r) {
            return n;
        }
        int64_t mid = (l+r) / 2;
        n->left = buildSegTree(nums, l, mid);
        n->right = buildSegTree(nums, mid+1, r);
        return n;
    }

    public:
        int64_t countRangeSum(vector<int>& nums, int lower, int upper) {
            if (nums.size() == 0) {
                return 0;
            }
            std::vector<int64_t> sums(nums.size(),0);
            sums[0] = nums[0];
            for (int64_t i = 1; i < nums.size(); ++i) {
                sums[i] = sums[i-1] + nums[i];
            }
            int64_t sum = *prev(sums.end());
            sort(sums.begin(), sums.end());

            std::vector<int64_t>::iterator uniq =
                std::unique(sums.begin(), sums.end());

            node * root = buildSegTree(sums, 0, uniq-sums.begin()-1);

            int64_t ans = 0;
            for (int64_t i = nums.size()-1; i >= 0; --i) {
                update(root, sum);
                sum -= nums[i];
                // sum = sum of nums from 0 to i-1
                ans += segsum(root, lower+sum, upper+sum);
            }
            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::vector<int> v = {-2, 5 -1};
    int lower = -2;
    int upper = 2;
    Solution s;
    s.countRangeSum(v, lower, upper);
    return 0;
}

