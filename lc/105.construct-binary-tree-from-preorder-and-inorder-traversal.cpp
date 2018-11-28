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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size()-1);
    }

    TreeNode * helper(
        vector<int> & pre, vector<int> & in,
        int preStart,
        int inBegin, int inEnd
    ) {
        if (preStart >= pre.size() || inBegin > inEnd) {
            return nullptr;
        }
        int r = pre[preStart];
        TreeNode * root = new TreeNode(r);
        int inIndex = 0;
        for (int i = inBegin; i <= inEnd; ++i) {
            if (in[i] == root->val){
                inIndex = i;
            }
        }
        root->left = helper(pre, in, preStart+1, inBegin, inIndex-1);
        root->right = helper(pre, in, preStart + (inIndex - inBegin) + 1, inIndex+1, inEnd);
        return root;
    }
};
