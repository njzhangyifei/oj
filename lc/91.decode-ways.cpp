class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);
        // if (s.size() == 0) return 0;

        dp[s.size()] = 1;

        if (s[s.size()-1] != '0') { 
            dp[s.size()-1] = 1;
        }

        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] == 0;
                continue;
            }
            int num = (s[i] - '0') * 10 + (s[i+1] - '0');
            
            if (1 <= num && num <= 26) {
                dp[i] = dp[i+1] + dp[i+2];
            } else {
                dp[i] = dp[i+1];
            }
        }

        return dp[0];
    }
};
