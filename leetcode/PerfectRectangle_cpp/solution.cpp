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

namespace std {
    ostream & operator << (ostream & os, pair<int,int> data){
        return os << '(' << data.first << ',' << data.second << ')' ;
    }
}

class Solution {
    public:
        void eraseOrInsert(std::set<string> & s, string p){
            if (s.find(p) != s.end()) {
                s.erase(p);
            } else {
                s.insert(p);
            }
        }

        bool isRectangleCover(vector<vector<int>>& rectangles) {
            pair<int, int> lb_large = {INT_MAX,INT_MAX};
            pair<int, int> rt_large = {-1, -1};
            std::set<string> s;
            int area = 0;
            for (size_t i = 0; i < rectangles.size(); ++i) {
                lb_large.first = min(lb_large.first, rectangles[i][0]);
                lb_large.second = min(lb_large.second, rectangles[i][1]);
                rt_large.first = max(rt_large.first, rectangles[i][2]);
                rt_large.second = max(rt_large.second, rectangles[i][3]);
                auto lb = "(" + std::to_string(rectangles[i][0]) + "," + std::to_string(rectangles[i][1]) + ")";
                auto rb = "(" + std::to_string(rectangles[i][2]) + "," + std::to_string(rectangles[i][1]) + ")";
                auto lt = "(" + std::to_string(rectangles[i][0]) + "," + std::to_string(rectangles[i][3]) + ")";
                auto rt = "(" + std::to_string(rectangles[i][2]) + "," + std::to_string(rectangles[i][3]) + ")";
                area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
                eraseOrInsert(s, lb);
                eraseOrInsert(s, rb);
                eraseOrInsert(s, lt);
                eraseOrInsert(s, rt);
            }
            auto lb_large_s = "(" + std::to_string(lb_large.first) + "," + std::to_string(lb_large.second) + ")";
            auto rb_large_s = "(" + std::to_string(rt_large.first) + "," + std::to_string(lb_large.second) + ")";
            auto lt_large_s = "(" + std::to_string(lb_large.first) + "," + std::to_string(rt_large.second) + ")";
            auto rt_large_s = "(" + std::to_string(rt_large.first) + "," + std::to_string(rt_large.second) + ")";
            auto area_large = (rt_large.first - lb_large.first) * (rt_large.second - lb_large.second);
            if (s.size() != 4) {
                return false;
            }
            if (s.find(lb_large_s) == s.end() || 
                s.find(rb_large_s) == s.end() || 
                s.find(lt_large_s) == s.end() || 
                s.find(rt_large_s) == s.end()) {
                return false;
            }
            if (area == area_large) {
                return true;
            }
            return false;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    Solution s;
    vector<vector<int>> input = 
        // {
        // {1,1,3,3},
        // {3,1,4,2},
        // {3,2,4,4},
        // {1,3,2,4},
        // {2,3,3,4}
        // };
        // {
        // {1,1,2,3},
        // {1,3,2,4},
        // {3,1,4,2},
        // {3,2,4,4}
        // };
        // {{1,1,2,2},{1,1,2,2},{2,1,3,2}};
    {{0,0,4,1},{7,0,8,2},{6,2,8,3},{5,1,6,3},{4,0,5,1},{6,0,7,2},{4,2,5,3},{2,1,4,3},{0,1,2,2},{0,2,2,3},{4,1,5,2},{5,0,6,1}};
    cerr << to_string(s.isRectangleCover(input)) << endl;
    return 0;
}

