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
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry = 1;
        for (int i = len-1; i >= 0; i--) {
            int num = digits[i] + carry; 
            carry = num / 10;
            digits[i] = num % 10;
        }
        vector<int> val;
        if (carry > 0) {
            val.push_back(carry);
        }
        std::copy(digits.begin(), digits.end(), std::back_inserter(val));
        return val;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

