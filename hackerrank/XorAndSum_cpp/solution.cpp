#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    uint32_t t = 0b10101010;

    cout << t << endl;

    uint32_t a = (t % 11) ^ (0b1011 % 11);
    uint32_t b = (t ^ 0b1011) % 11;
    cout << a << endl;
    cout << b << endl;

    return 0;
}

