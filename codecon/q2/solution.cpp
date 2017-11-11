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
#include <unordered_set>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    uint64_t res = 0;
    cin >> N; 

    int upper = ceil(sqrt((double)(N/3.0)));
    int count = 0;

    for (int x = 0; x < upper; x++) {
        int x_sq = x*x;
        int y = x;
        int rest_upper = sqrt(N-x_sq);
        while (y <= rest_upper && x <= y) {
            int y_sq = y*y;
            int z_sq = rest_upper * rest_upper;
            int sum = x_sq + y_sq + z_sq;
            if (sum == N) {
                res += x + y + rest_upper;
                y ++;
                continue;
            }
            if (sum < N) {
                y ++;
            } else if (sum > N) {
                rest_upper --;
            }
        }
    }

    cout << res << endl;
    return 0;
}

