#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <iomanip>
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

void solve(int N){
    std::vector<int> v;
    int i;
    for (i = 0; i < N; ++i) {
        int c;
        cin >> c;
        v.push_back(c);
    }

    std::priority_queue<int, vector<int>, std::less<int>> q_lower ;
    std::priority_queue<int, vector<int>, std::greater<int>> q_upper;

    q_upper.push(v[0]);
    cout << std::fixed << std::setprecision(1) << (double)v[0] << endl;
    for (i = 1; i < N; ++i) {
        int num = v[i];
        double median;
        if (num < q_upper.top()) {
            q_lower.push(num);
        } else {
            q_upper.push(num);
        }
        if (q_lower.size() < q_upper.size()) {
            while (q_lower.size() < q_upper.size()) {
                q_lower.push(q_upper.top());
                q_upper.pop();
            }
        } else {
            while (q_upper.size() < q_lower.size()) {
                q_upper.push(q_lower.top());
                q_lower.pop();
            }
        }
        if (q_upper.size() > q_lower.size()) {
            median = q_upper.top();
        } else {
            median = q_lower.top();
        }
        if (q_lower.size() == q_upper.size()) {
            median = ((double) q_lower.top() + q_upper.top()) / 2.0;
        }
        cout << std::fixed << std::setprecision(1) << median << endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    solve(N);
    return 0;
}

