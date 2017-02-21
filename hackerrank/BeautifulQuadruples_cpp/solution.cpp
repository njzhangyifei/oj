#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

std::vector<int> size;

struct quadruple {
    int W;
    int X;
    int Y;
    int Z;

    quadruple(int w, int x, int y, int z){
        W = w;
        X = x;
        Y = y;
        Z = z;
    }

    ostream & operator << (ostream & s){
        s << "(" << W << ", " << X << ", " << Y << ", " << Z << ")";
        return s;
    }
};

int binary_search(vector<int> * v, int val){
    int lo = 0;
    int hi = v->size();
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        ans = mid;
        if (mid == v->size()) {
            break;
        }
        int current_val = v->operator[](mid);
        if (current_val > val) {
            if (mid == 0) {
                break;
            }
            if (v->operator[](mid-1) <= val) {
                break;
            }
        }
        if (current_val > val) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int i, j;

    for (i = 0; i < 4; ++i) {
        int val;
        cin >> val;
        size.push_back(val);
    }

    sort(size.begin(), size.end());

    #ifdef DEBUG
    for (auto i : size) {
        cout << i << " ";
    }
    cout << endl;
    #endif

    std::map<int, vector<int> *> xor_value_map;

    for (i = 1; i <= size[0]; ++i) {
        for (j = i; j <= size[1]; ++j) {
            int val = i ^ j;
            if (xor_value_map.find(val) == xor_value_map.end()) {
                xor_value_map[val] = new std::vector<int>;
                xor_value_map[val]->push_back(j);
            } else {
                xor_value_map[val]->push_back(j);
            }
        }
    }

    for (auto i : xor_value_map) {
        sort(i.second->begin(), i.second->end());
    }

    int64_t matching_count = 0;
    for (i = 1; i <= size[2]; ++i) {
        for (j = i; j <= size[3]; ++j) {
            // the second pair
            int val = i ^ j;
            if (xor_value_map.find(val) != xor_value_map.end()) {
                int num = binary_search(xor_value_map[val], i);
                if (num != 0) {
                    matching_count += num;
                    #ifdef DEBUG
                    cout << num << " <- ";
                    cout << i << ", " << j << endl;
                    #endif
                }
            }
        }
    }

    int64_t total = 0;
    for (i = 1; i <= size[0]; ++i) {
        for (j = i; j <= size[1]; ++j) {
            int64_t C = size[2];
            int64_t D = size[3];
            int64_t num_terms = (C - j + 1);
            int64_t decreasing_start = (D - j + 1); 

            int64_t t = decreasing_start + (decreasing_start - num_terms + 1);
            int64_t res = t * num_terms;
            total += res / 2;

        }
    }

    #ifdef DEBUG
    cerr << total << endl;
    #endif

    int64_t ans = total - matching_count;

    cout << ans << endl;
    
    return 0;
}

