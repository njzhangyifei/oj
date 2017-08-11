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

            point(point * other){
                left = other->left;
                height = other->height;
            }
        };

        struct skyline {
            vector<point *> points;

            skyline * merge(skyline * r){
                int l_index = 0;
                int r_index = 0;
                skyline * s = new skyline();
                while (l_index < this->points.size() && r_index < r->points.size()) {
                    auto left_point = this->points[l_index];
                    auto right_point = r->points[r_index];
                    if (left_point->left < right_point->left){
                        s->points.push_back(new point(left_point));
                        l_index++;
                        continue;
                    } else if (left_point->left == right_point->left){
                        s->points.push_back(
                                new point(left_point->left, 
                                    max(right_point->height, left_point->height)
                                    ));
                        l_index++;
                        r_index++;
                    } else {
                        s->points.push_back(new point(right_point));
                        r_index++;
                    }
                }
                for (;  r_index < r->points.size(); r_index++) {
                    s->points.push_back(new point(this->points[r_index]));
                }
                return s;
            }
        };

        skyline * get_skyline(vector<vector<int>> & buildings, int left, int right){
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
            skyline * t = get_skyline(buildings, 0, buildings.size());
            vector<pair<int, int>> ans;
            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<int>> input = 
        {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    Solution s;
    s.getSkyline(input);
    return 0;
}

