#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <unordered_map>
#include <iterator>
#include <iomanip>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int64_t factorial_table [] ={
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800,
    39916800,
    479001600,
    6227020800,
    87178291200,
    1307674368000,
    20922789888000,
    355687428096000,
    6402373705728000,
};

double solve(vector<int> * v){
    sort(v->begin(), v->end());

    ostream_iterator<int> os(cout, ", ");
    unordered_map<int, int> map;

    for (auto i : *v) {
        map[i]++;
    }

    int64_t total_perm_size  = factorial_table[v->size()];
    int64_t distinct_perm_size = total_perm_size;

    for (auto i : map) {
        distinct_perm_size /= factorial_table[i.second];
    }

    int64_t num_perm = distinct_perm_size;

    // if (num_perm == 1) {
        // // all the same
        // return 0;
    // }

    return (double)num_perm;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    int i;

    std::vector<int> v;

    uint8_t sorted = 1;
    // check if sorted

    int prev_num = INT_MIN;
    for (i = 0; i < N; ++i) {
        int num;
        cin >> num;
        v.push_back(num);
        if (num > prev_num) {
            prev_num = num;
        } else {
            prev_num = num;
            sorted = 0;
        }
    }

    if (sorted) {
        cout << fixed << setprecision(6) << 0.0 << endl;
    } else {
        cout << fixed << setprecision(6) << solve(&v) << endl;
    }

    return 0;
}

