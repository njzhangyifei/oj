class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int lo = 0;
        int hi = nums.size()-1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[lo] <= nums[mid]) {
                // left side is sorted
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            } else {
                // right side is sorted
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
        }

        return -1;
    }
};
