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
        TreeNode* construct(vector<int> nums, int begin, int end) {
            if (begin >= end) {
                return NULL;
            }
            if (begin + 1 == end) {
                return new TreeNode(nums[begin]);
            }
            int max = 0;
            int max_index = 0;
            for (int i = begin; i < end; ++i) {
                if (max < nums[i]) {
                    max =  nums[i];
                    max_index = i;
                }
            }
            TreeNode * l = construct(nums, begin, max_index);
            TreeNode * r = construct(nums, max_index+1, end);
            TreeNode * node = new TreeNode(max);
            node->left = l;
            node->right = r;
            return node;
        }

        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return construct(nums, 0, nums.size());
        }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

