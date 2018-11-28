class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (int i = 0; i < wordDict.size(); i++) {
            dict.insert(wordDict[i]);
        }

        vector<bool> dp = vector<bool>(s.size() + 1,false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j ++) {
                string subs = s.substr(j, i-j);
                if (dp[j] && dict.find(subs) != dict.end()) {
                    // found
                    dp[i] = true ;
                }
            }
        }

        return dp[s.size()];
    }
};
