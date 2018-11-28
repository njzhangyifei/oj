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
    int maxoverall;

    int maxPathSum(TreeNode* root) {
        maxoverall = INT_MIN;
        rec(root);
        return maxoverall;
    }

    int rec(TreeNode* root) {
        if (root == nullptr) return 0;

        int left =  max(rec(root->left), 0);
        int right = max(rec(root->right), 0);

        int via_root = root->val + max(left, right);
        int full_tree = root->val + left + right;

        maxoverall = max(maxoverall, full_tree);

        return via_root;
    }

};
