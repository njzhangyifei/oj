class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1;

        for (int i = 0; i < nums1.size(); ++i) {
            n1.insert(nums1[i]);
        }

        vector<int> res;
        for (int i = 0; i < nums2.size(); ++i) {
            int n = nums2[i];
            if (n1.find(n) != n1.end()) {
                n1.erase(n);
                res.push_back(n);
            }
        }

        return res;
    }
};
