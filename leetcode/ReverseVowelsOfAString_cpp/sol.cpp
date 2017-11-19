#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isV(char c) {
        if (
                c == 'a' || c == 'e' || c == 'i' || c=='o' || c=='u' ||
                c == 'A' || c == 'E' || c == 'I' || c=='O' || c=='U'
        ) {
            return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;
        while (left < right) {
            if (isV(s[left]) && isV(s[right])) {
                swap(s[left], s[right]);
                left ++;
                right --;
            } else if (isV(s[left])) {
                right --;
            } else if (isV(s[right])) {
                left ++;
            } else {
                left ++; right --;
            }
        }
        return s;
    }

    // string reverseVowels(string s) {
        // std::vector<char> v;
        // string out ("");
        // for (int i = 0; i < s.size(); ++i) {
            // if (isV(s[i])) {
                // v.push_back(s[i]);
            // }
        // }
        // reverse(v.begin(), v.end());
        // for (int i = 0; i < s.size(); ++i) {
            // if (isV(s[i])) {
                // out.push_back(v.back());
                // v.pop_back();
            // } else {
                // out.push_back(s[i]);
            // }
        // }
        // return out;
    // }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

