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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::vector<uint64_t> v;
    int i;
    for (i = 0; i < 5; ++i) {
        uint64_t t = 0;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    cout << ( v[0] + v[1] + v[2] + v[3]);
    cout << " ";
    cout << ( v[1] + v[2] + v[3] + v[4]);
    return 0;
}

