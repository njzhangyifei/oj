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

// *
// * Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {

    public:
        vector<int> flatten(TreeNode * root){
            if (root == NULL) {
                return vector<int>();
            }
            vector<int> l = flatten(root->left);
            auto r = flatten(root->right);
            l.push_back(root->val);
            std::copy(r.begin(), r.end(), std::back_inserter(l));
            return l;
        }

        bool findTarget(TreeNode* root, int k) {
            std::vector<int> v  = flatten(root);
            std::set<int> map;
            for (int i = 0; i < v.size(); ++i) {
                int el = v[i];
                int diff = k - el;
                if (map.find(diff) != map.end()) {
                    // ok
                    return true;
                }
                map.insert(el);
            }
            return false;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

