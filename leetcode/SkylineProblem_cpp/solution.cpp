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

ostream & operator << (ostream & os, point p) {
    return os << '(' << p.left << ',' << p.height << ')';
}

class Solution {
    public:

        struct skyline {
            vector<point *> points;

            void append(point * p){
                if (points.size() && points[points.size()-1]->height == p->height) {
                    return;
                }
                if (points.size() && points[points.size()-1]->left == p->left) {
                    int h = points[points.size()-1]->height;
                    points[points.size()-1]->height = max(h, p->height);
                    return;
                }
                points.push_back(p);
            }

            skyline * merge(skyline * r){
                if (r == nullptr) {
                    skyline * s = new skyline();
                    for (int i = 0; i < points.size(); ++i) {
                        s->append(new point(points[i]));
                    }
                    return s;
                }
                int l_index = 0;
                int r_index = 0;
                int l_height = 0;
                int r_height = 0;
                skyline * s = new skyline();
                while (l_index < this->points.size() && r_index < r->points.size()) {
                    auto left_point = this->points[l_index];
                    auto right_point = r->points[r_index];
                    if (left_point->left < right_point->left){
                        l_height = left_point->height;
                        s->append(
                                new point(left_point->left,
                                    max(l_height, r_height)
                                    )
                            );
                        l_index++;
                    } else {
                        r_height = right_point->height;
                        s->append(
                                new point(right_point->left,
                                    max(l_height, r_height)
                                    )
                            );
                        r_index++;
                    }
                }
                for (;  l_index < points.size(); l_index++) {
                    s->append(new point(points[l_index]));
                }
                for (;  r_index < r->points.size(); r_index++) {
                    s->append(new point(r->points[r_index]));
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
            auto mid = (left + right + 1) / 2;
            skyline * l = get_skyline(buildings, left, mid);
            skyline * r = get_skyline(buildings, mid, right);
            skyline * t = l->merge(r);
            delete l;
            if (r) {
                delete r;
            }
            return t;
        }

        vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
            skyline * t = get_skyline(buildings, 0, buildings.size());
            for (auto i : t->points) {
                cerr << *i << endl;
            }
            vector<pair<int, int>> ans;
            for (int i = 0; i < t->points.size(); ++i) {
                // ans.push(make_pair()
            }
            // for (auto i : ans) {
                // cerr << i.first << ',' << i.second << endl;
            // }
            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<int>> input =
    // {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    // {{2,9,10},{3,7,15}};
    {{1,2,1},{1,2,2},{1,2,3}};
    Solution s;
    s.getSkyline(input);
    return 0;
}

