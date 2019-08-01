class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0;;
        int counter = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] > nums[i-1]) {
                counter += 1;
                res = max(counter, res);
            } else {
                counter = 1;
            }
        }
        return res;
    }
};
