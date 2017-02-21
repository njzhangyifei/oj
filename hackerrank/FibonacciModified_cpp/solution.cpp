#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int a, b, n;
    cin >> a >> b >> n;
    std::vector<int> v;
    v.push_back(a);
    v.push_back(b);

    int i;
    for (i = 0; i < n-2; ++i) {
        int t_n = v[i];
        int t_n_1 = v[i+1];
        int t_n_2 = (t_n_1 * t_n_1) + t_n;
        v.push_back(t_n_2);
    }

    cout << v.back();

    return 0;
}
