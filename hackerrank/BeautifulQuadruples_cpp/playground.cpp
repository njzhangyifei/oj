#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_A = 10;
const int MAX_B = 10;
const int MAX_C = 14;
const int MAX_D = 15;

// const int MAX_A = 7;
// const int MAX_B = 7;
// const int MAX_C = 7;
// const int MAX_D = 7;


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

};

ostream & operator << (ostream & s, quadruple & q){
    return s << "(" 
        << q.W << ", " 
        << q.X << ", " 
        << q.Y << ", " 
        << q.Z << ")";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i, j, k, l;
    int max_max = max(MAX_A, MAX_B);
    max_max = max(max_max, MAX_C);
    max_max = max(max_max, MAX_D);
    std::vector<pair<int, int>> matched_half;

    std::map<int, int> xor_value_map;
    cout << "xor value table:" << endl;
    for (i = 1; i <= max_max; ++i) {
        for (j = i; j <= max_max; ++j) {
            int val = i^j;
            if (xor_value_map[val]) {
                // this is a match
                if (i <= MAX_C && j <= MAX_D && i < j) {
                    // output this match
                    pair<int, int> p(i, j);
                    matched_half.push_back(p);
                }
            }
            if (i <= MAX_A && j <= MAX_B) {
                xor_value_map[val] ++;
            }
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "matched_half:" << endl;
    for (auto i : matched_half) {
        cout << i.first << ", " << i.second << endl;
    }

    cout << "xor value map:" << endl;
    for (auto i : xor_value_map) {
        cout << "[" << i.first << "] " << i.second << endl;
    }

    std::vector<quadruple> v_special_illegal;
    int total = 0;
    int ans = 0;
    int special_illegal  = 0;
    int matching_illegal = 0;
    for (i = 1; i <= MAX_A; ++i) {
        for (j = i; j <= MAX_B; ++j) {
            for (k = j; k <= MAX_C; ++k) {
                for (l = k; l <= MAX_D; ++l) {
                    cout << i << " " << j << " " << k << " " << l;
                    if ((((i ^ j) ^ k) ^ l) != 0) {
                        cout << " - beautiful";
                        ans += 1;
                    } else {
                        if (i == j && k == l) {
                            matching_illegal += 1;
                        } else {
                            special_illegal += 1;
                            v_special_illegal.push_back
                                (quadruple(i, j, k, l));
                        }
                    }
                    cout << endl;
                    total += 1;
                }
            }
        }
    }

    cout << "special_illegal quadruple:" << endl;
    for (quadruple i : v_special_illegal) {
        // auto temp = i.X;
        // i.X = i.Y;
        // i.Y = temp;
        cout << i << endl;
    }

    cout << "total = " << total << endl;
    cout << "matching illegal = " << matching_illegal << endl;
    cout << "special illegal = " << special_illegal << endl;
    cout << "ans = " << ans << endl;

    return 0;
}

