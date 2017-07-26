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
        string intToRoman(int num) {
            map<int, string, std::greater<int>> m = {
                { 1000, "M"},
                { 900, "CM" },
                { 500, "D" },
                { 400, "CD" },
                { 100, "C" },
                { 90, "XC" },
                { 50, "L" },
                { 40, "XL" },
                { 10, "X" },
                { 9, "IX" },
                { 5, "V" },
                { 1, "I" },
                { 0, "" },
            };

            string s = "";

            while (num != 0) {
                cerr << "num=" << num << endl;
                for (auto i : m) {
                    if (i.first <= num) {
                        num -= i.first;
                        s += i.second;
                        break;
                    } else {
                        continue;
                    }
                }
            }

            return s;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int IN;
    cin >> IN;

    Solution s;
    cout << s.intToRoman(IN) << endl;
    return 0;
}

