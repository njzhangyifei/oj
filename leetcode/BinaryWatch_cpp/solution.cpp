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
#include <bitset>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<string> readBinaryWatch(int num) {
            vector<string> ans;
            for (int i = 0; i < 12; ++i) {
                for (int j = 0; j < 60; ++j) {
                    bitset<10> s(i << 6 | j);
                    if (s.count() == num) {
                        ans.emplace_back(
                                to_string(i)
                                + (j < 10 ? ":0" : ":") 
                                + to_string(j)
                                );
                    }
                }
            }
            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

