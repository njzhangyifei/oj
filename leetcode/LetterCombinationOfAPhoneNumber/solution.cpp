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
        vector<string> letterCombinations(string digits) {

            std::vector<string> v = {
                "",
                "",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz",
            };

            std::vector<string> v_current;
            v_current.push_back("");
            for (int i = 0; i < digits.length(); ++i) {
                int digit = digits[i] - '0';
                string perm_s = v[digit];
                if (perm_s == "") {
                    return vector<string>();
                }

                std::vector<string> v_new;
                for (auto l : v_current) {
                    for (int j = 0; j < perm_s.size(); ++j) {
                        v_new.push_back(l + perm_s[j]);
                    }
                }
                v_current = v_new;
            }

            // sort(v_current);
            return v_current;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    Solution s;
    auto t = s.letterCombinations("23233");
    for (auto i : t) {
        cerr << i << endl;
    }
    return 0;
}

