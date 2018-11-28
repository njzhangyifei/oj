class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> height;
        for (int i = 0; i < buildings.size(); i++) {
            height.push_back(make_pair(buildings[i][0], buildings[i][2]));
            height.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }

        sort(height.begin(), height.end());

                            // H , end
        priority_queue<pair<int, int>> pq;


        vector<pair<int, int>> res;
        int b_i = 0;
        for (int i = 0; i < height.size(); i++) {
            pair<int, int> curr = height[i];

            // end before this critical point
            while (!pq.empty() && pq.top().second <= curr.first) {
                pq.pop();
            }

            while (b_i < buildings.size()) {
                // comes before end
                if (buildings[b_i][0] <= curr.first) {
                    pq.push( make_pair(buildings[b_i][2], buildings[b_i][1]) );
                    ++b_i;
                } else {
                    break;
                }
            }

            int height = 0;
            if (!pq.empty()) {
                height = pq.top().first;
            }

            pair<int, int> p = make_pair(curr.first, height);
            if (res.size() > 0 && p.second == res.back().second) {
                continue;
            }

            res.push_back(p);
        }

        return res;
    }
};
