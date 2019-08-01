class Solution {
public:
    bool isMatch(string s, string p) {
       vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));

        dp[0][0] = true;

        // eliminate a*b* = "" case
        for (int j = 1; j < p.size(); ++j) {
            if (p[j] == '*' && dp[0][j-1]) {
                dp[0][j+1] = true;
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                if (s[i] == p[j]) {
                    dp[i+1][j+1] = dp[i][j];
                }
                if (p[j] == '.') {
                    dp[i+1][j+1] = dp[i][j];
                }
                if (p[j] == '*') {
                    if (p[j-1] == s[i] || p[j-1] == '.') {
                        // previous matches
                        dp[i+1][j+1] = dp[i+1][j-1] || dp[i+1][j] || dp[i][j+1];
                    } else {
                        // no match
                        dp[i+1][j+1] = dp[i+1][j-1];
                    }
                }
            }
        }

        return dp[s.size()][p.size()];


        // if (p.size() == 0) {
        //     return s.size() == 0;
        // }
        
        // bool firstMatch = (s.size() > 0) && (s[0] == p[0] || p[0] == '.');

        // if (p.size() > 1 && p[1] == '*') {
        //     return (firstMatch && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
        // } else {
        //     return firstMatch && isMatch(s.substr(1), p.substr(1));
        // }
    }
};
