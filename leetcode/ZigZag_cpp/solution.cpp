#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <sstream>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1) {
                return s;
            }
            vector<string> map(numRows);
            auto str_len = s.length();
            if (str_len == 0) {
                return "";
            }
            bool increasing = false;
            int cur_row = 0;
            for (int i = 0; i < str_len; ++i) {
                if (cur_row == 0 || cur_row == numRows-1) {
                    increasing = !increasing;
                }
                map[cur_row].push_back(s[i]);
                cur_row += (increasing ? 1 : -1);
            }
            string sss("");
            for (int i = 0; i < numRows; ++i) {
                sss += map[i];
            }
            return sss;
        }

        string convert_s(string s, int numRows) {
            auto strlen = s.length();
            int map[strlen][numRows];
            for (int i = 0; i < strlen; ++i) {
                for (int j = 0; j < numRows; ++j) {
                    map[i][j] = -1;
                }
            }
            int cur_row = 0;
            int cur_col = 0;
            bool going_up = false;
            for (int i = 0; i < strlen; ++i) {
                map[cur_col][cur_row] = s[i];
                if (cur_row == numRows-1 || going_up) {
                    cur_row --;
                    cur_col ++;
                    going_up = (cur_row != 0);
                } else {
                    cur_row++;
                }
            }

            stringstream ss;
            for (int j = 0; j < numRows; ++j) {
                for (int i = 0; i < strlen; ++i) {
                    if (map[i][j] != -1) {
                        ss << (char)map[i][j];
                    }
                }
            }
            return ss.str();
        }

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    Solution sln;
    auto out = sln.convert("abcdefghi", 4);
    cout << "---OUTPUT--"  << endl << out << endl;

    return 0;
}

