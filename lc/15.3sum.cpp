class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>();
        }
        
        sort(nums.begin(), nums.end());

        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        } 

        vector<vector<int>> res;

        for (int i = 0; i < nums.size()-2; ++ i) {
            if (i == 0  || nums[i-1] != nums[i]) {
                // avoid repetition

                for (int j = i+1; j < nums.size()-1; ++j) {
                    if (j == i+1  || nums[j-1] != nums[j]) {
                        int rem = - (nums[i] + nums[j]);
                        if (m.find(rem) != m.end()) {
                            if (m[rem] > j) {
                                vector<int> c;
                                c.push_back(nums[i]);
                                c.push_back(nums[j]);
                                c.push_back(nums[m[rem]]);
                                res.push_back(c);
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};
