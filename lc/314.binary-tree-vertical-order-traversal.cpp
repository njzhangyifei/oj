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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<int, TreeNode *>> q;
        map<int, vector<int>> m;

        if (root) { 
            q.push(make_pair(0, root));
        }


        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                pair<int, TreeNode*> entry = q.front();
                q.pop();
                m[entry.first].push_back(entry.second->val);

                TreeNode * n = entry.second;
                if (n->left) {
                    q.push(make_pair(entry.first - 1, n->left));
                }
                if (n->right) {
                    q.push(make_pair(entry.first + 1, n->right));
                }
            }
        }

        vector<vector<int>> res;
        for (auto e: m) {
            res.emplace_back(e.second);
        }
        return res;
    }
};
