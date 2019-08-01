class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        // unordered_map<int, int> m;
        // for (int i = 0; i < nums1.size(); ++i) {
        //     m[nums1[i]] += 1;
        // }
        
        // for (int i = 0; i < nums2.size(); ++i) {
        //     int n2 = nums2[i];

        //     // atmost m [n2] times

        //     if (m.find(n2) != m.end()) { 
        //         m[n2] -= 1;
        //         if (m[n2] < 0) {
        //             m.erase(n2);
        //         } else {
        //             res.push_back(n2);
        //         }
        //     }
        // }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i ++;
                j ++;
            } else {
                if (nums1[i] > nums2[j]) {
                    j ++;
                } else {
                    i ++;
                }
            }
        }

        return res;
    }
};
