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

class Solution {
    public:
        struct TrieNode {
            bool isWord;
            vector<int> words;
            TrieNode * children [26] = {NULL};

        };


        TrieNode * buildTrie (vector<string> & ss) {
            TrieNode * root = new TrieNode();
            for (int i = 0; i < ss.size(); ++i) {
                TrieNode * curr = root;
                for (int j = 0; j < ss[i].size(); ++j) {
                    int idx = ss[i][j] - 'a';
                    if (curr->children[idx] == NULL) {
                        curr->children[idx] = new TrieNode();
                    }
                    curr = curr->children[idx];
                    curr->words.push_back(i);
                }
                curr->isWord = true;
            }
            return root;
        }

        void solve (
                vector<vector<string>> & res,
                vector<string> & words,
                int size,
                int level, 
                vector<string> & used,
                TrieNode * root
                )
        {
            if (level == size) {
                res.push_back(used);
                return;
            }

            std::vector<int> v_path;
            for (int i = 0; i < level; ++i) {
                v_path.push_back(used[i][level] - 'a');
            }

            
            TrieNode * child = root;
            for (int i = 0; i < v_path.size(); ++i) {
                if (child->children[v_path[i]] == NULL) {
                    // non-exist
                    return;
                }
                child = child->children[v_path[i]];
            }

            for (int i = 0; i < child->words.size(); ++i) {
                used.push_back(words[child->words[i]]);
                solve(res, words, size, level + 1, used, root);
                used.pop_back();
            }
        }

        vector<vector<string>> wordSquares(vector<string>& words) {
            TrieNode * root = buildTrie(words);
            std::vector<vector<string>> res;
            std::vector<string> used;
            int sz = words[0].size();
            for (int i = 0; i < words.size(); ++i) {
                used.push_back(words[i]);
                solve(res, words, sz, 1, used, root);
                used.pop_back();
            }

            return res;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

