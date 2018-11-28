/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p) return p;
        if (root == q) return q;

        TreeNode * l = lowestCommonAncestor(root->left, p, q);
        TreeNode * r = lowestCommonAncestor(root->right, p, q);

        if (l && r) {
            return root;
        } else if (l) {
            return l;
        } else {
            return r;
        }
    }
};
