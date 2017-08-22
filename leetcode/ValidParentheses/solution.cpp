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
    bool isValid(string s) {
        stack<char> sym;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '(' ||
                ch == '{' ||
                ch == '[') {
                sym.push(ch);
                continue;
            } 
            char exp = ' ';
            if (ch == ')') {
                exp = '(';
            } else if (ch == '}') {
                exp = '{';
            } else if (ch == ']') {
                exp = '[';
            }
            if (sym.size() && sym.top() == exp) {
                sym.pop();
            } else {
                return false;
            }
        }
        if (sym.size()) {
            return false;
        }
        return true;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

