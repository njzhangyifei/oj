class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> len(nums.size(), 1);
        vector<int> cnt(nums.size(), 1);

        int max_len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    // cnt update when len == len -1
                    if (len[i] == len[j] + 1) {
                        cnt[i] = cnt[i] + cnt[j];
                    } else if (len[i] < (len[j] + 1)) {
                        // len ending with j longer than ending with i
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            max_len = max(len[i], max_len);
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (len[i] == max_len) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};
