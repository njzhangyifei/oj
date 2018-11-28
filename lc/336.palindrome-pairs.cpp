class Solution {
public:
    unordered_map<string, int> reversed; 
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;

        for (int i = 0; i < words.size(); ++i) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            reversed[rev] = i;
        }
 
        if (reversed.find("") != reversed.end()) {
            // found empty string
            int idx = reversed[""];
            for (int i = 0; i < words.size(); ++i) {
                if (words[i].size() != 0 && isPalindrome(words[i])) {
                    res.push_back({i, idx});
                    res.push_back({idx, i});
                }
            }
        }

        for (int i = 0; i < words.size(); ++i) {
            string w = words[i];
            if (reversed.find(w) != reversed.end() && reversed[w] != i) {
                res.push_back({i, reversed[w]});
            }
            for (int j = 1; j < words[i].size(); ++j) {
                string left  = words[i].substr(0, j);
                string right = words[i].substr(j);

                // left | right | rev(left)
                if (reversed.find(left) != reversed.end() && isPalindrome(right) && reversed[left] != i) {
                    res.push_back({i, reversed[left]});
                }

                // rev(right) | left | right
                if (reversed.find(right) != reversed.end() && isPalindrome(left) && reversed[right] != i) {
                    res.push_back({reversed[right], i});
                }
            }
        }

        return res;
    }

    bool isPalindrome(const string & s) {
        int l = 0;
        int r = s.size()-1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
