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

#define DEBUG

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

    int max_size = size.back();

    std::unordered_set<int64_t> special_illegal_xor_set;
    std::map<int64_t, int64_t> xor_value_map;
    std::map<int64_t, int64_t>
    int64_t special_illegal = 0;
    for (i = 1; i <= size[2]; ++i) {
        for (j = i; j <= size[3]; ++j) {
            int64_t val = i^j;
            if (xor_value_map.find(val) != xor_value_map.end()) {
                xor_value_map[val] ++;
            } else {
                xor_value_map[val] = 1;
            }
        }
    }

    #ifdef DEBUG
    for (auto i : xor_value_map) {
        cout << i.first << " : " << i.second << endl;
    }
    #endif

    special_illegal = 0;
    for (auto i : xor_value_map) {
        if (i.first != 0) {
            int64_t count = i.second;
            special_illegal += count * count / 2;
        }
    }

    int64_t total = 0;
    for (i = 1; i <= size[0]; ++i) {
        for (j = i; j <= size[1]; ++j) {
            int64_t C = size[2];
            int64_t D = size[3];
            // 1 1 1 1   5
            // 1 1 1 2
            // 1 1 1 3
            // 1 1 1 4
            // 1 1 1 5
            //
            // 1 1 2 2   4
            // 1 1 2 3
            // 1 1 2 4
            // 1 1 2 5
            //
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

    int64_t min_first = min(size[0], size[1]);
    int64_t min_second = min(size[2], size[3]);
    int64_t matching_illegal = 0;
    for (i = 0; i < min_first; ++i) {
        matching_illegal += (min_second - i);
    }

    #ifdef DEBUG
    cerr << "matching_illegal : " << matching_illegal << endl;
    cerr << "special_illegal : " << special_illegal << endl;
    #endif

    int64_t ans = total - matching_illegal - special_illegal;

    cout << ans << endl;
    
    return 0;
}

