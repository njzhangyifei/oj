#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
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
        string decodeString(string s) {
            std::stack<string> ss;
            std::stack<int> val;
            for (int i = 0; i < s.length(); ) {
                int before;
                if (s[i] == '[') {
                    ss.push("[");
                    i++;
                } else if (s[i] == ']') {
                    // cerr << "pop " << val.top() << endl;
                    // cerr << "pop " << ss.top() << endl;
                    int repeat = val.top();
                    val.pop();
                    string ssss = "";
                    while (ss.size() && ss.top() != "[") {
                        ssss = ss.top() + ssss;
                        ss.pop();
                    }
                    if (ss.top() == "[") {
                        ss.pop();
                    }
                    string new_s = "";
                    for (int j = 0; j < repeat; ++j) {
                        new_s += ssss;
                    }
                    // if (ss.size()) {
                        // new_s = ss.top() + new_s;
                        // cerr << "pop " << ss.top() << endl;
                        // ss.pop();
                    // }
                    // cerr << "push " << new_s << endl;
                    ss.push(new_s);
                    i++;
                    continue;
                }
                before = i;
                while (s[i] <= '9' && s[i] >= '0') {
                    // is a number
                    i ++;
                }
                if (i - before != 0) {
                    int num = std::stoi(s.substr(before, i - before));
                    val.push(num);
                    // cerr << "push " << num << endl;
                }

                before = i;
                while (s[i] <= 'z' && s[i] >= 'a') {
                    // is a number
                    i ++;
                }
                if (i - before != 0) {
                    string str = s.substr(before, i - before);
                    ss.push(str);
                    // cerr << "push " << str << endl;
                }
            }
            string output = "";
            while (ss.size()) {
                output = ss.top() + output;
                ss.pop();
            }
            return output;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution sl;
    // auto s = "3[a]2[bc]";
    // auto s = "3[a2[c]]";
    auto s = "2[abc]3[cd]ef";
    // auto s = "2[2[b]]";
    // auto s = "sd2[f2[e]g]i";
    auto sln = sl.decodeString(s);
    cerr << sln << endl;
    return 0;
}

