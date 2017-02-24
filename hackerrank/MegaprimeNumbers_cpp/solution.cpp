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
#include <cmath>
using namespace std;

#define PRIME_DIGIT(x) ((x == 2) || (x == 3) || (x==5) || (x==7))
std::vector<int> digits = {2, 3, 5, 7};
std::vector<uint64_t> v_num;

void rec (uint64_t current, uint64_t numdigits) {
    if (numdigits == 0) {
        v_num.push_back(current);
    } else {
        if (numdigits != 1 || current == 0) {
            for (auto i : digits) {
                rec(current * 10 + i, numdigits - 1);
            }
        } else {
            rec(current * 10 + 3, numdigits - 1);
            rec(current * 10 + 7, numdigits - 1);
        }
    }
}
bool is_prime(uint64_t a) {
    if (a < 2) {
        return false;
    }
    if (PRIME_DIGIT(a)) {
        return true;
    }
    if (a % 2 == 0) {
        return false;
    }
    if (a % 5 == 0) {
        return false;
    }
    if (a % 11 == 0) {
        return false;
    }
    uint64_t i;
    for (i = 3; (i*i) <= a; i+=2) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int countDigits( uint64_t value )
{
    int result = 0;
    while( value != 0 ) {
       value /= 10;
       result++;
    }
    return result;
}

uint64_t solve(uint64_t first, uint64_t last) 
{
    uint64_t li;
    uint64_t count = 0;

    int f_d = countDigits(first);
    int l_d = countDigits(last);

    int i;
    for (i = f_d; i <= l_d; ++i) {
        rec(0, i);
    }

    for (auto i : v_num) {
        if ( (i >= first) && (i <= last) && is_prime(i) ) {
            // cout << i << endl;
            count ++;
        }
    }

    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    uint64_t first, last;
    cin >> first >> last;
    // 
    cout << solve(first, last) << endl;
    return 0;
}

