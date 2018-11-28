class Solution {
public:
    vector<int> n;
    Solution(vector<int> nums) {
        n = nums;
    }
    
    int pick(int target) {
        int count = 0, ans = -1;
        for (int i = 0; i < n.size(); i++) {
            if (n[i] != target) continue;
            ++count;
            if (count == 1) {
                ans = i;
            } else {
                // (1/n+1)
                if (rand() % count == 0){
                    ans = i;
                }
            }
        }
        return ans;
    }

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
