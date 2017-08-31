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
        string addStrings(string num1, string num2) {
            int len_1 = num1.size();
            int len_2 = num2.size();

            string ret("");
            int carry = 0;
            for (int i = 1; i <= max(len_1, len_2); ++i) {
                int n1 = 0;
                int n2 = 0;
                if (len_1 - i >= 0) {
                    n1 = num1[len_1-i] - '0';
                }
                if (len_2 - i >= 0) {
                    n2 = num2[len_2-i] - '0';
                }
                int res = n1+n2+carry;
                carry = res / 10;
                res = res % 10;
                ret.push_back(res + '0');
            }
            if (carry > 0) {
                ret.push_back(carry + '0');
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

