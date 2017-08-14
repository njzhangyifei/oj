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
        vector<Interval> merge(vector<Interval>& intervals) {
            if (intervals.size() == 0) {
                return vector<Interval>();
            }
            std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ 
                    return a.start < b.start;
                    });
            vector<Interval> ans;
            ans.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); ++i) {
                if (intervals[i].start < ans.back().end) {
                    //merge
                    ans.back().end = max(ans.back().end, intervals[i].end);
                } else {
                    ans.push_back(intervals[i]);
                }
            }
            return ans;
        }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

