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

class Solution {
    public:
        int findNthDigit(int n) {
            if (n == 0) {
                return 1;
            }
            // base 9
            int len = 1;
            int64_t count = 9;
            int start =1;

            while (n > len * count) {
                n -= len * count;
                len += 1;
                count *= 10;
                start *= 10;
            }

            start += (n-1) / len;

            string s = to_string(start);
            return s[(n-1)  % len] - '0';
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution s;
    cerr << s.findNthDigit(3)  << endl;
    cerr << s.findNthDigit(10)  << endl;
    cerr << s.findNthDigit(11) << endl;
    return 0;
}

