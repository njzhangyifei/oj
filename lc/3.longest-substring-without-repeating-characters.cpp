class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> map(256, false);

        if (s.size() == 0){
            return 0;
        }

        int left = 0;
        int right = 0;
        int max_len = 0;

        while (right < s.size()) {
            char ch = s[right];
            if (!map[ch]) {
                map[ch] = true;
                right ++;
                // update max len
                max_len = max(max_len, (right-left));
            } else {
                int new_left = left;
                bool found = false;
                for (int i = right - 1; i >= left; i--) {
                    if (found) {
                        map[s[i]] = false;
                    }
                    if (ch == s[i]) {
                        // found last one, start from here
                        new_left = i+1;
                        found = true;
                    }
                }
                left = new_left;
                right ++;
            }
        }

        return max_len;
    }
};
