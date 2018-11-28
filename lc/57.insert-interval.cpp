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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;

        int i = 0;
        for (; i < intervals.size(); ++i) {
            if (intervals[i].end < newInterval.start) {
                res.push_back(intervals[i]);
            } else {
                break;
            }
        }
        // intervals[i] overlaps with newInterval
        for (; i < intervals.size(); ++i) { 
            if (intervals[i].start <= newInterval.end) {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
            } else {
                break;
            }
        }
        res.push_back(newInterval);
        for (; i < intervals.size(); ++i) { 
            res.push_back(intervals[i]);
        }
        return res;
    }
};
