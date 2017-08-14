#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <sstream>
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

class Codec {
    public:
        string to_string(TreeNode * t){
            if (t == NULL || t == nullptr) {
                return "null";
            }
            return std::to_string(t->val);
        }

        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            std::vector<string> v;
            std::queue<TreeNode *> q;
            q.push(root);
            while (q.size()) {
                TreeNode * t = q.front();
                q.pop();
                v.push_back(to_string(t));
                if (t) {
                    q.push(t->left);
                    q.push(t->right);
                }
            }
            string s = "[";
            for (auto i : v) {
                s += i + ",";
            }
            s[s.size()-1] = ']';
            return s;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            std::stringstream ss(data.substr(1, data.size()-2));
            string s;
            std::vector<TreeNode *> v;
            while (getline(ss, s, ',')) {
                if (s == "null") {
                    v.push_back(NULL);
                } else {
                    v.push_back(new TreeNode(std::stoi(s)));
                }
            }
            std::queue<TreeNode *> q; 
            q.push(v[0]);
            for (int i = 1; i < v.size(); ++i) {
                TreeNode * node = q.front();
                q.pop();
                node->left = v[i++];
                node->right = v[i];
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            return v[0];
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

