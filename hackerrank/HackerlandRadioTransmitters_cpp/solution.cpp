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

int solve(int N, bool house[], int range){
    bool covered[500100] = {false};
    int i;
    int count = 0;
    for (i = 0; i < 100001; ++i) {
        if (house[i] && (!covered[i])) {
            int t;
            if (!house[i+range]) {
                int far_house = i;
                for (t = 0; t < range + 1; ++t) {
                    if (house[i+t]) {
                        far_house = i+t;
                    }
                    covered[i+t] = true;
                }
                for (t = 0; t < range+1; ++t) {
                    covered[far_house+t] = true;
                }
            } else {
                for (t = 0; t < 2*range + 1; ++t) {
                    covered[i+t] = true;
                }
            }
            count ++;
            // cout << "tx at " << i << endl;
        }
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N;
    int Range;
    
    cin >> N >> Range;

    int i;
    bool house[200100] = {false};
    for (i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        house[temp] = true;
    }

    cout << solve(N, house, Range);

    return 0;
}

