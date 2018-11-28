class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        int left = 0;
        int right = height.size()-1;
        int max_left = height[left];
        int max_right = height[right];
        int total = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                max_left = max(max_left, height[left]);
                total += max_left - height[left];
                left ++;
            } else {
                max_right = max(max_right, height[right]);
                total += max_right - height[right];
                right --;
            }
        }
        return total;
    }
};
