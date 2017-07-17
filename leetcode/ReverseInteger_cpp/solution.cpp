#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <stack>
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
        int reverse(int x) {
            std::queue<int> s_digit;
            while (x != 0) {
                int digit = x % 10;
                s_digit.push(digit);
                x = x / 10;
            }
            long long val = 0;
            while (s_digit.size()) {
                int digit = s_digit.front();
                s_digit.pop();
                val = val * 10 + digit;
                if (val > INT_MAX || val < INT_MIN) {
                    val = 0;
                    break;
                }
            }
            return (int)val;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution sln;
    cout << sln.reverse(123) ;
    cout << endl;

    cout << sln.reverse(-123);
    cout << endl;

    cout << sln.reverse(1534236469);
    cout << endl;
    return 0;
}

