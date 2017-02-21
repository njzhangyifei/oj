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
#include <iomanip>
#include <iostream>
#include <ios>
#include <algorithm>
using namespace std;

struct matrix_2x2 {
    double a1, a2;
    double a3, a4;
    
    matrix_2x2(double a1, double a2, double a3, double a4)
    {
        this->a1 = a1;
        this->a2 = a2;
        this->a3 = a3;
        this->a4 = a4;
    }

    double det(){
        return a1*a4 - a2*a3;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x, y;
    int a, b;

    cin >> x >> y;
    cin >> a >> b;

    matrix_2x2 original(a, -b, b, a);

    matrix_2x2 original_1 = original;
    original_1.a1 = x;
    original_1.a3 = y;

    matrix_2x2 original_2 = original;
    original_2.a2 = x;
    original_2.a4 = y;

    double k = original_1.det() / original.det();
    double n = original_2.det() / original.det();

    cout.precision(5);
    cout << fixed << k << endl;
    cout << fixed << n << endl;

    return 0;
}

