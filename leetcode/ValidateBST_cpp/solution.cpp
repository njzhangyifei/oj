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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool isValidBST(TreeNode * root, int64_t min, int64_t max){
            if (!root) {
                return true;
            }
            if (root->val >= max) {
                return false;
            }
            if (root->val <= min) {
                return false;
            }
            bool valid = true;
            if (root->left) {
                valid &= isValidBST(root->left, min, root->val);
            }
            if (root->right) {
                valid &= isValidBST(root->right, root->val, max);
            }
            return valid;
        }

        bool isValidBST(TreeNode* root) {
            return isValidBST(root, INT64_MIN, INT64_MAX);
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

