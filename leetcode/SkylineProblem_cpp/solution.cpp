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

class Solution {
    public:
        struct point {
            int left;
            int height;

            point(int l, int h) {
                left = l;
                height = h;
            }
        };

        struct skyline {
            vector<point *> points;

            skyline * merge(skyline * r){
                int l_index = 0;
                int r_index = 0;
                while (l_index < this->points.size() && r_index < r->points.size()) {

                }
                return nullptr;
            }
        };

        skyline * get_skyline(vector<vector<int>>buildings, int left, int right){
            if (left >= right) {
                return nullptr;
            }
            if (left + 1 == right) {
                auto t = new skyline();
                t->points.push_back(new point(
                            buildings[left][0],
                            buildings[left][2]
                            ));
                t->points.push_back(new point(
                            buildings[left][1],
                            0
                            ));
                return t;
            }
            auto mid = (left + right) / 2;
            skyline * l = get_skyline(buildings, left, mid);
            skyline * r = get_skyline(buildings, mid, right);
            skyline * t = l->merge(r);
            delete l; delete r;
            return t;
        }

        vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

