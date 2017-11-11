#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) {
            return false;
        }
        std::bitset<sizeof(int) * 8> bs(n);
        return (bs.count() == 1);
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

