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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N, M;
    cin >> N >> M;

    int cookie_per_person = M / N;

    int ans = 0;
    if (M == N || (M % N == 0)) {
        ans = 0;
    } else {
        ans = (cookie_per_person+1) * N - M;
    }

    cout << ans << endl;
    return 0;
}

