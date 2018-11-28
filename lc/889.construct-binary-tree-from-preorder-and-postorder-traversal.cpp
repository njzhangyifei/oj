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
    unordered_map<int, int> pre_pos;
    unordered_map<int, int> post_pos;

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for (int i = 0; i < pre.size(); i ++) {
            pre_pos[pre[i]] = i;
            post_pos[post[i]] = i;
        }

        return construct(pre, post, 0, pre.size(), 0, post.size());
    }

    TreeNode* construct(vector<int> & pre, vector<int> & post, int pre_begin, int pre_end, int post_begin, int post_end) {
        if (pre_begin < 0 || pre_begin >= pre_end || post_begin < 0 || post_begin >= post_end ||
            pre_end > pre.size() || post_end > post.size() || (pre_end - pre_begin) != (post_end - post_begin))  {
            return nullptr;
        }
        int pre_root = pre[pre_begin];
        int post_root = post[post_end-1];

        if (pre_root != post_root) {
            return nullptr;
        } 


        TreeNode * node = new TreeNode(pre_root);    

        if (pre_end - pre_begin == 1 || post_end - post_begin == 1) {
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }

        if (pre[pre_begin+1] == post[post_end-2]){
            // either left or right
            node->left = construct(pre,post,
                pre_begin+1, pre_end,
                post_begin, post_end-1
            );
            node->right = nullptr;
        } else {
            node->left = construct(pre, post,
                pre_begin+1, pre_pos[post[post_end-2]],
                post_begin, post_pos[pre[pre_begin+1]] + 1
            );
            node->right = construct(pre, post,
                pre_pos[post[post_end-2]], pre_end,
                post_pos[pre[pre_begin+1]]+1, post_end-1 // right post
            );
        }
        return node;
    }
};
