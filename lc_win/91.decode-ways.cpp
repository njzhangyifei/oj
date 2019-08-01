class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if ( n == 0) return 0;

        vector<int> dp(n+1, 0);
        dp[n] = 1;
        if (s[n-1] != '0') {
            dp[n-1] = 1;
        }

        for (int i = n-2; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            int num = (s[i] - '0') * 10 + (s[i+1] - '0');
            if (num <= 26) {
                dp[i] = dp[i+1] + dp[i+2];
            } else {
                dp[i] = dp[i+1];
            }
        }

        return dp[0];
    }
};
