#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

std::vector<int> non_important;
std::vector<int> important;

int solve(int N, int K) {
    int sum = 0;
    sort(important.begin(), important.end());

    // cout << "important:" << endl;
    // for (auto i : important) {
        // cout << i << " ";
    // }
    // cout << endl;
    
    int i;
    int to_win = N - K - non_important.size();
    for (i = 0; i < important.size(); ++i) {
        if (i < to_win) {
            sum -= important[i];   
        } else {
            sum += important[i];   
        }
    }

    for (i = 0; i < non_important.size(); ++i) {
        sum += non_important[i];
    }

    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N;
    int K;
    
    cin >> N >> K;

    int i;

    for (i = 0; i < N; ++i) {
        int L;
        int T;
        cin >> L >> T;
        if (T) {
            important.push_back(L);
        } else {
            non_important.push_back(L);
        }
    }

    cout << solve(N, K) << endl;

    return 0;
}

