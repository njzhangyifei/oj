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

class Solution {
public:
    struct node {
        node * parent;
        bool word;
        node * children [26];
        node (node * p = nullptr) {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
            word = false;
            parent = p;
        }

    };

    string explore(vector<vector<char>> & board)

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node * trie = new node();
        for (size_t i = 0; i < words.size(); ++i) {
            string w = words[i];
            auto root = trie;
            for (size_t j = 0; j < w.size(); ++j) {
                auto t = new node();
                root->children[w[j]-'a'] = t;
                root = t;
            }
            root->word = true;
        }

        vector<string> t;
        return t;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

