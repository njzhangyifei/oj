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

#define DEBUG

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;

    int i;
    std::vector<float> v_sides;
    for (i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        v_sides.push_back(temp);
    }

    if (N == 1) {
        cout << "2" << endl;
        return 0;
    }
    
    int ans = 0;
    while (true) {
        sort(v_sides.begin(), v_sides.end());

        #ifdef DEBUG
        cerr << "v_sides:" << endl;
        for (auto i : v_sides) {
            cerr << i << ", ";
        }
        cerr << endl;
        #endif


        float longest = v_sides.back();
        float sum_front = 0;
        for (i = 0; i < v_sides.size() - 1; ++i) {
            sum_front += v_sides[i];
        }

        if (longest >= sum_front) {
            ans ++;
            float chopped = ((float)longest) / ((float) (ans + 1));
            v_sides[v_sides.size() - 1] = chopped;
            for (i = 0; i < ans; ++i) {
                v_sides.push_back(chopped);
            }
        } else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}

