class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        remove(s, res, 0, 0, {'(', ')'});
        return res;
    }

    void remove(string & s, vector<string> & res, int last_i, int last_j, const vector<char> & parens) {
        int stack = 0;
        for (int i = last_i; i < s.size(); ++i) {
            if (s[i] == parens[0]) stack ++;
            if (s[i] == parens[1]) stack --;
            if (stack >= 0) continue;
            
            // more paren[1], start finding the first one after last_j before i
            for (int j = last_j; j <= i; j++) {
                if (s[j] == parens[1] && (j == last_j || s[j - 1] != parens[1])) {
                    string removed = s.substr(0, j) + s.substr(j+1, s.size()-j);
                    remove(removed, res, i, j, parens);
                }
            }
            return;
        }

        string reversed = s;
        reverse(reversed.begin(), reversed.end());

        if (parens[0] == '(') {
            remove(reversed, res, 0, 0, {')', '('});
        } else {
            res.push_back(reversed);
        }
    } 
};
