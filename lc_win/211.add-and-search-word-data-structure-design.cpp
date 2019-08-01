class WordDictionary {
public:
    struct TrieNode {
        bool isWord;
        vector<TrieNode*> c;

        TrieNode() {
            isWord = false;
            c = vector<TrieNode*>(26, nullptr);
        }
    };

    TrieNode * root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode * curr = root;
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i] - 'a';
            if (curr->c[ch] == nullptr) {
                curr->c[ch] = new TrieNode();
            } 
            curr = curr->c[ch];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return rec(word, root);
    }

    bool rec(string word, TrieNode * root) {
        if (word.size() == 0) {
            return root->isWord;
        }
        TrieNode * curr = root;
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            if (ch != '.') {
                ch -= 'a';
                if (curr->c[ch] != nullptr) {
                    curr = curr->c[ch];
                } else {
                    // cannot go further
                    return false;
                }
            } else {
                for (int j = 0; j < 26; ++j) {
                    if (curr->c[j] != nullptr) {
                        bool res = rec(word.substr(i+1), curr->c[j]);
                        if (res) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        return curr->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
