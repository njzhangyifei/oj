class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
        }
        
        int longest = 1;
        for (auto i : s) {
            if (s.find(i-1) == s.end()) {
                // does not have i-1
                int l = 1;
                int curr = i;
                while (s.find(curr+1) != s.end()) {
                    curr += 1;
                    l ++;
                    longest = max(longest, l);
                }
            }
        }

        return longest;
    }
};
