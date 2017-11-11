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
    string fractionToDecimal(int numerator, int denominator) {
        // 4/3 = 1.33333
        if (numerator == 0) {
            return "0";
        }

        bool neg = (numerator < 0) ^ (denominator < 0);
        int64_t num = abs((int64_t) numerator);
        int64_t den = abs((int64_t) denominator);
        int64_t int_part = num / den;
        int64_t rem_part = abs(num - int_part * den);

        string f;
        if (neg) {
            f.append("-");
        }
        f.append(std::to_string(int_part));
        if (rem_part == 0) {
            return f;
        }
        f.append(".");
        string t;
        unordered_map<int64_t, size_t> pos_map;
        while (true) {
            if (rem_part == 0) {
                f.append(t);
                break;
            }
            int res = rem_part * 10 / den;
            if (pos_map.find(rem_part) == pos_map.end()) {
                pos_map.insert(make_pair(rem_part, t.size()));
                t.push_back(res + '0');
            } else {
                f.append(t.substr(0, pos_map[rem_part]));
                f.append("(");
                f.append(t.substr(pos_map[rem_part], t.size() - pos_map[rem_part]));
                f.append(")");
                break;
            }
            rem_part = rem_part * 10 - res * den;
        }
        return f;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

