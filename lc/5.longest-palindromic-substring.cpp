class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        string longest_s;

        for (int i = 0; i < s.size(); i ++) {
            int len_odd = expand(s, i, i);
            int len_even = expand(s, i, i + 1);

            int len = max(len_even, len_odd);

            if (len > longest) {
                longest = len;
                longest_s = s.substr(i-((len-1)/2), len);
            }
        }

        return longest_s;
    }



    int expand(const string & s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l --;
            r ++;
        };
        return r - l - 1;
    }
};
