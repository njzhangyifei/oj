/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return vector<Interval>();
        }
        sort(intervals.begin(), intervals.end(), [](const Interval & l, const Interval & r) -> bool {
            return l.start < r.start;
        });
        

        vector<Interval> res;
        Interval curr = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (curr.end >= intervals[i].start) {
                // merge
                curr.end = max(curr.end, intervals[i].end);
            } else {
                // cannot merge
                res.push_back(curr);
                curr = intervals[i];
            }
        }
        res.push_back(curr);
        return res;
    }
};
