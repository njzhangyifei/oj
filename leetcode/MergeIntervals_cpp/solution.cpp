#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_set>
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
    vector<Interval> merge(vector<Interval>& intervals) {
        std::vector<Interval> res;
        if (intervals.size() == 0) {
            return res;
        }
        sort(intervals.begin(), intervals.end(), 
            [](const Interval & l, const Interval & r) {
            return l.start > r.start;
        });

        res.push_back(intervals.back());
        intervals.pop_back();

        while (intervals.size()) {
            auto interval = intervals.back();
            if (interval.end <= res.back().end) {
                intervals.pop_back();
                continue;
            } else if (interval.start <= res.back().end && 
                interval.end >= res.back().end) {
                res.back().end = interval.end;
            } else {
                res.push_back(interval);
            }
            intervals.pop_back();
        }

        return res;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

