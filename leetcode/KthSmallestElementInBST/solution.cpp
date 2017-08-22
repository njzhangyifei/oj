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
        int res;
        int explore(TreeNode* root, int k) {
            if (root == NULL) {
                return 0;
            }
            if (k <= 0 ) {
                return -1;
            }
            int l = explore(root->left, k);
            if (l < 0 || k <= 0) {
                return -1;
            }
            k -= l;
            if (k == 0) {
                res = root->val;
                return -1;
            }
            k -= 1;
            int r = explore(root->right, k);
            if (r < 0 || k <= 0) {
                return -1;
            }
            return l + r + 1;
        }

        int kthSmallest(TreeNode* root, int k) {
            explore(root, k);
            return 0;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

