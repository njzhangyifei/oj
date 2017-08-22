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
        string word_string;
        node (node * p = nullptr) {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
            word = false;
            parent = p;
        }

    };

    std::vector<pair<int, int>> direction = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    void explore(
            vector<vector<char>> & board, 
            std::set<pair<int, int>> explored,
            node * parent,
            set<string> & ans,
            int i, int j, int row_num, int col_num){
        for (auto d : direction) {
            if ((i + d.first >=0) && (i + d.first < row_num)
                &&(j + d.second >=0) && (j + d.second < col_num))  {
                // safe
                char ch = board[i+d.first][j+d.second];
                node * child = parent->children[ch-'a'];
                if (!child) {
                    // liu le
                    continue;
                } 
                auto next = make_pair(i+d.first, j+d.second);
                if (explored.find(next) != explored.end()) {
                    // explored
                    continue;
                }
                if (child->word) {
                    ans.insert(child->word_string);
                }
                explored.insert(next);
                explore(board, explored, 
                        child, ans, i+d.first, j+d.second, row_num, col_num);
                explored.erase(next);
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row_num = board.size();
        if (row_num == 0) {
            return vector<string>();
        }
        int col_num = board[0].size();
        if (col_num == 0) {
            return vector<string>();
        }
        node * trie = new node();
        for (size_t i = 0; i < words.size(); ++i) {
            string w = words[i];
            auto root = trie;
            for (size_t j = 0; j < w.size(); ++j) {
                node * child = root->children[w[j]-'a'] ;
                root->children[w[j]-'a'] = (child != nullptr) ? child : new node();
                root = root->children[w[j]-'a'];
            }
            root->word = true;
            root->word_string = w;
        }

        std::set<string> ans;
        for (int i = 0; i < row_num; ++i) {
            for (int j = 0; j < col_num; ++j) {
            // int i = 0, j = 0;
                std::set<pair<int, int>> explored;
                char ch = board[i][j];
                node * start = trie->children[ch-'a'];
                explored.insert(make_pair(i, j));
                if (start == nullptr) {
                    // continue;
                }
                if (start->word) {
                    ans.insert(start->word_string);
                }
                explore(board, explored, start, ans, i, j, row_num, col_num);
            }
        }

        vector<string> t;
        for (auto i : ans) {
            t.push_back(i);
        }
        return t;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<vector<char>> board = 
    // { {'o', 'a','a','n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}}; 
    // {{'a','b'},{'c','d'}};
    {{'b','a','a','b','a','b'},{'a','b','a','a','a','a'},{'a','b','a','a','a','b'},{'a','b','a','b','b','a'},{'a','a','b','b','a','b'},{'a','a','b','b','b','a'},{'a','a','b','a','a','b'}};


    vector<string> dict = 
    // {"aa","pea","eat","rain"}; 
    // {"ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"};
    {"bbaabaabaaaaabaababaaaaababb","aabbaaabaaabaabaaaaaabbaaaba","babaababbbbbbbaabaababaabaaa","bbbaaabaabbaaababababbbbbaaa","babbabbbbaabbabaaaaaabbbaaab","bbbababbbbbbbababbabbbbbabaa","babababbababaabbbbabbbbabbba","abbbbbbaabaaabaaababaabbabba","aabaabababbbbbbababbbababbaa","aabbbbabbaababaaaabababbaaba","ababaababaaabbabbaabbaabbaba","abaabbbaaaaababbbaaaaabbbaab","aabbabaabaabbabababaaabbbaab","baaabaaaabbabaaabaabababaaaa","aaabbabaaaababbabbaabbaabbaa","aaabaaaaabaabbabaabbbbaabaaa","abbaabbaaaabbaababababbaabbb","baabaababbbbaaaabaaabbababbb","aabaababbaababbaaabaabababab","abbaaabbaabaabaabbbbaabbbbbb","aaababaabbaaabbbaaabbabbabab","bbababbbabbbbabbbbabbbbbabaa","abbbaabbbaaababbbababbababba","bbbbbbbabbbababbabaabababaab","aaaababaabbbbabaaaaabaaaaabb","bbaaabbbbabbaaabbaabbabbaaba","aabaabbbbaabaabbabaabababaaa","abbababbbaababaabbababababbb","aabbbabbaaaababbbbabbababbbb","babbbaabababbbbbbbbbaabbabaa"};

    Solution s;
    auto t = s.findWords(board, dict);
    cerr << "ans :" << endl;
    for (auto i : t) {
        cerr << i << endl;
    }
    return 0;
}

