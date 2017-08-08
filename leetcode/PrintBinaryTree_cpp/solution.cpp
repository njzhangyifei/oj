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
        int treeHeight = 0;
        void go(TreeNode  * root, int currentHeight){
            if (root == NULL) {
                return;
            }
            go(root->left, currentHeight+1);
            go(root->right, currentHeight+1);
            treeHeight = max(currentHeight, treeHeight);
        }

        vector<vector<string>> printTree(TreeNode* root) {
            go(root, 0);
            cerr << this->treeHeight << endl;
            int width = 0;
            for (int i = 0; i < treeHeight; ++i) {
                width += 1 << i;
            }
            std::vector<vector<string>> v;
            for (int i = 0; i < treeHeight; ++i) {
                auto s=  vector<string>();
                for (int j = 0; j < width; ++j) {
                    s.push_back("");
                }
                v.push_back(s);
            }
            return v;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

