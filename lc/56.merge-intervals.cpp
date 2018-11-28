/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return vector<Interval>();   
        }
        std::priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>,
            std::greater<pair<int, int>>> pq;
        for (int i = 0; i < intervals.size(); ++i) {
            pq.push(make_pair(intervals[i].start, intervals[i].end));
        }

        vector<Interval> res;
        pair<int, int> curr = pq.top();
        pq.pop();
        while (pq.size()) {
            pair<int, int> top = pq.top();
            pq.pop();
            if (top.first <= curr.second) {
                // merge
                curr.second = max(top.second, curr.second);
            } else {
                // cannot merge
                res.push_back(Interval(curr.first, curr.second));
                curr = top;
            }
        }
        res.push_back(Interval(curr.first, curr.second));
        return res;
    }
};
