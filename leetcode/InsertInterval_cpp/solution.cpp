#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
        vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
            vector<Interval> res;
            int i;
            for (i = 0; i < intervals.size(); ++i) {
                int start = intervals[i].start;
                int end = intervals[i].end;
                if (end < newInterval.start) {
                    res.push_back(intervals[i]);
                } else if (start > newInterval.end){
                    break;
                } else {
                    newInterval.start = 
                        min(start, newInterval.start);
                    newInterval.end = 
                        max(end, newInterval.end);
                }
            }
            res.push_back(newInterval);
            for (;  i < intervals.size(); i++) {
                intervals.push_back(intervals[i]);
            }
            return res;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

