class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 0) {
            return 0;
        }

        if(nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp0(nums.size(),0);
        vector<int> dp1(nums.size(),0);

        dp0[0] = 0;
        dp0[1] = nums[1];

        dp1[0] = nums[0];
        dp1[1] = nums[0];

        for (int i = 2; i < nums.size(); ++i) {
            dp0[i] = max(dp0[i-2] + nums[i], dp0[i-1]);
            dp1[i] = max(dp1[i-2] + nums[i], dp1[i-1]);
        }

        return max(dp0[nums.size()-1], dp1[nums.size()-2]);
    }
};
