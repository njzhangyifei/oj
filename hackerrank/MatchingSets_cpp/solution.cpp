#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <set>
#include <map>
#include <memory>
#include <numeric>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int i;

    cin >> N;
    unique_ptr<vector<int64_t>> v_orig(new vector<int64_t>());
    unique_ptr<vector<int64_t>> v_after(new vector<int64_t>());
    for (i = 0; i < N; ++i) {
        int64_t temp;
        cin >> temp;
        v_orig->push_back(temp);
    }
    sort(v_orig->begin(), v_orig->end());

    for (i = 0; i < N; ++i) {
        int64_t temp;
        cin >> temp;
        v_after->push_back(temp);
    }
    sort(v_after->begin(), v_after->end());

    int64_t sum_orig = std::accumulate(v_orig->begin(), v_orig->end(),   (int64_t)0);
    int64_t sum_after = std::accumulate(v_after->begin(), v_after->end(),(int64_t)0);

    cerr << "sum_orig: " << sum_orig << endl;
    cerr << "sum_after: " << sum_after << endl;
    if (sum_orig != sum_after) {
        cout << "-1" << endl;
        return 0;
    }

    if (N == 1) {
        cout << "0" << endl;
        return 0;
    }

    int64_t sum_diff = 0;
    for (i = 0; i < N; ++i) {
        int64_t orig = v_orig->operator[](i);
        int64_t after = v_after->operator[](i);
        sum_diff += abs(orig-after);
    }
    sum_diff /= 2;

    cout << sum_diff;

    return 0;
}

