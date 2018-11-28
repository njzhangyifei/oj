class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        perm(res, nums, 0);
        return res;
    }

    void perm(vector<vector<int>> & res, vector<int> & nums, int begin) {
        if (begin >= nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            swap(nums[i], nums[begin]);
            perm(res, nums, begin+1);
            swap(nums[i], nums[begin]);
        }
    }
};
