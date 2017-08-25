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
    struct node {
        int l; int r;
        int count;
        node * left; node * right;

        node (int l, int r){
            this->l = l; this->r = r;
            this->count = 0;
            this->left = nullptr; this->right= nullptr;
        }
    };

    node * buildSegTree(vector<int> & nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        node * root = new node(l, r);
        if (l == r) {
            return root;
        }
        int mid = (l+r)/2;
        root->left = buildSegTree(nums, l, mid);
        root->left = buildSegTree(nums, mid+1, r);
        return root;
    }

    int segsum (node * root, int l, int r) {
        if (root == nullptr || root->r < l || r < root->l) {
            return 0;
        }
        if (l <= root->l && root->r <= r) {
            // completely inside
            return root->count;
        }
        return segsum(root->left, l, r) + segsum(root->right, l, r);
    }

    void update(node * root, int val) {
        if (root != nullptr && root->l <= val && val <= root->r) {
            root->count ++;
            update(root->left, val);
            update(root->right, val);
        }
    }

    public:
    vector<int> countSmaller(vector<int>& nums) {
        std::vector<int> v(nums.begin(), nums.end());
        std::sort(v.begin(), v.end());

        std::vector<int> ans(nums.size(), 0);
        return ans;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

