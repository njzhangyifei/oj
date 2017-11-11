#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

bool worst;
vector<int> kicksort(vector<int> n){
    if (n.size() <= 1) {
        return n;
    }
    std::vector<int> B;
    std::vector<int> C;
    int P_index = (n.size() -1) / 2;
    for (int i = 0; i < n.size(); ++i) {
        if (i == P_index) {
            continue;
        }
        if (n[i] <= n[P_index]) {
            B.push_back(n[i]);
        } else {
            C.push_back(n[i]);
        }
    }
    if (B.size() != 0 && C.size() != 0) {
        worst = false;
    }
    std::vector<int> res;
    std::vector<int> B_res = kicksort(B);
    for (int i = 0; i < B_res.size(); ++i) {
        res.push_back(B_res[i]);
    }
    res.push_back(n[P_index]);
    std::vector<int> C_res = kicksort(C);
    for (int i = 0; i < C_res.size(); ++i) {
        res.push_back(C_res[i]);
    }
    return res;
}

void check_worst(int caseno){
    int N;
    cin >> N;
    std::vector<int> v_n;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        v_n.push_back(temp);
    }
    worst = true;
    kicksort(v_n);
    cout << "Case #" << caseno << ": " << (worst? "YES" : "NO") << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        check_worst(i+1);
    }
    return 0;
}

