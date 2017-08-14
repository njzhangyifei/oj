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
        bool check_vowel(char c){
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
                ;
        }
        string reverseVowels(string s) {
            std::vector<char> v;
            for (int i = 0; i < s.size(); ++i) {
                if (check_vowel(s[i])) {
                    v.push_back(s[i]);
                }
            }
            for (int i = 0; i < s.size(); ++i) {
                if (check_vowel(s[i])) {
                    s[i] = v.back();
                    v.pop_back();
                }
            }
            return s;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

