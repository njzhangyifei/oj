#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_set>
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
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            unordered_map<string, TreeNode *> map;
            vector<TreeNode *> res;
            string s = serialize(root, map, res);
            return res;
        }

        string serialize(
                TreeNode * node, 
                unordered_map<string, TreeNode *> & map,
                vector<TreeNode *> & found){
            string res("");
            res += "(";
            if (node->left) {
                string l = serialize(node->left, map, found);
                res += l + ",";
            } 
            res += to_string(node->val);
            if (node->right) {
                string r = serialize(node->left, map, found);
                res += "," + r;
            }
            res += ")";
            if (map.find(res) != map.end()) {
                if (map[res] != NULL) {
                    found.push_back(map[res]);
                    map[res] = NULL;
                }
            } else { 
                map[res] = node;
            }
            return res;
        }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

