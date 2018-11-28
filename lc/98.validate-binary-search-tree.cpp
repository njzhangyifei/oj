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
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }

    bool validate(TreeNode * root, TreeNode * minnode, TreeNode * maxnode) {
        if (root == nullptr) return true;

        if (minnode && root->val <= minnode->val) return false;
        if (maxnode && root->val >= maxnode->val) return false;

        return validate(root->left, minnode, root) && validate(root->right, root, maxnode);
    }
};
