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

class Solution {
    public:
        struct interval{
            int start;
            int end;
            interval(int start, int end) {
                this->start = start;
                this->end = end;
            }
        };

        vector<interval> mergeInterval(vector<interval> & in) {
            vector<interval> res;
            if (in.size() == 0) return res;
            sort(in.begin(), in.end(), [](const interval & l, const interval & r) {
                    return l.start > r.start;
                    });

            res.push_back(in.back());
            in.pop_back();

            while (in.size()) {
                if (in.back().end <= res.back().end){
                    //
                } else if (in.back().end >= res.back().end && in.back().start <= res.back().end + 1 ){
                    // update end
                    res.back().end = in.back().end;
                } else {
                    res.push_back(in.back());
                }
                in.pop_back();
            }

            return res;
        }

        string addBoldTag(string s, vector<string>& dict) {
            vector<interval> found;
            for (auto d : dict) {
                auto pos = s.find(d);
                while (pos != string::npos) {
                    // add pos
                    // "abc" 0 1 2, size = 3, last = start + size -1
                    found.push_back(interval(pos, pos+d.size()-1)); 
                    pos = s.find(d, pos+1);
                }
            }
            vector<interval> out = mergeInterval(found);
            // for (int i =0; i < out.size(); i++) {
                // cout << out[i].start  << " -> " << out[i].end << endl;
            // }
            string output("");
            int j = 0;
            for (int i =0; i < out.size(); i++) {
                interval curr = out[i];
                for (;j < curr.start; j ++) {
                    output.push_back(s[j]);
                }
                output += "<b>";
                for (;j <= curr.end; j++) {
                    output.push_back(s[j]);
                }
                output += "</b>";
            };
            for (; j < s.size(); j ++){
                output.push_back(s[j]);
            }
            return output;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

