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

void solve(int caseno){
    int N;
    cin >> N;

    std::vector<int> v(N+1, 0);

    for (int i = 0; i < N+1; ++i) {
        v[i] = i;
    }

    for (int i = std::sqrt(N+1)+1; i > 1; i--) {
        if (i*i > N+1) {
            continue;
        }
        for (int j = 0; j < N+1; ++j) {
            if (j - i*i >= 0) {
                v[j] = min(v[j - i*i]+1, v[j]);
            }
        }
    }
    cout << "Case #" << caseno << ": " << v[N] << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve(i+1);
    }
    return 0;
}

