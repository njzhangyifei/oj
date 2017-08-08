#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
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
        struct filename {
            string filename;
            int abs_length;
            int level;
            struct filename * parent;

            string get_string() const {
                return "" + filename + 
                    ", level=" + std::to_string(level) + 
                    ", abslen=" + std::to_string(abs_length);
            }
        };

        bool isFile(string fn) {
            auto t = fn.find('.');
            return t != string::npos;
        }

        int lengthLongestPath(string input) {
            std::map<int, filename *> last_parent_map;
            size_t longest = 0;
            last_parent_map[-1] = nullptr;
            int level = 0;
            for (size_t i = 0; i < input.length(); ++i) {
                while (input[i] == '\t') {
                    i++;
                    level ++;
                }
                size_t filename_start = i;
                while (input[i] != '\n' && i < input.length()) {
                    i++;
                }
                size_t filename_end = i;
                string fn = input.substr(filename_start, filename_end - filename_start);
                filename * f = new filename();
                auto * parent = last_parent_map[level-1];
                size_t len = fn.length();
                if (parent != nullptr) {
                    len += parent->abs_length;
                }
                f->filename = fn;
                f->level = level;
                f->parent = parent;
                f->abs_length = len;
                if (!isFile(fn)) {
                    last_parent_map[level] = f;
                    // add slash
                    f->abs_length += 1; 
                } else {
                    if (len > longest) {
                        longest = len;
                    }
                }
                cerr << "filename = " << f->get_string() << endl;
                level = 0;
            }
            return longest;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution s;

    string a = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    string b = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    auto ans = s.lengthLongestPath("a\n\ta\n\t\ta");
    cerr << ans << endl;
    return 0;
}

