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

    unordered_map<TreeNode *, int> mem;

    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (mem.find(root) != mem.end()) {
            return mem[root];
        }

        int grandchildren = 0;

        if (root->left) { 
            grandchildren += rob(root->left->left);
            grandchildren += rob(root->left->right);
        } 

        if (root->right) { 
            grandchildren += rob(root->right->left);
            grandchildren += rob(root->right->right);
        } 

        int res =  max(grandchildren + root->val, rob(root->left) + rob(root->right)) ;
        mem[root] = res;

        return res;
    }
};
