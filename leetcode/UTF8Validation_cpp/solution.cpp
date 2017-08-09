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

#define MASK (0xF8)
#define MASK_SUB (0xC0)

class Solution {
public:
    int nbit(uint8_t head){
        int nbit = 0;
        uint8_t masked = head & MASK;
        if ((masked & 0x80) == 0) {
            nbit = 1;
        }
        if ((masked & 0xC0) == 0xC0) {
            nbit = 2;
        }
        if ((masked & 0xE0) == 0xE0) {
            nbit = 3;
        }
        if (masked == 0xF0) {
            nbit = 4;
        }
        return nbit;
    }

    bool validUtf8(vector<int>& data) {
        size_t i = 0;
        while (i < data.size()) {
            // cerr << data[i] << endl;
            int n = nbit(data[i++]);
            if (n == 0) {
                return false;
            }
            // cerr << n << "-bit found" << endl;
            n--;
            for (; n > 0 ; n--) {
                // cerr << n << endl;
                if ((data[i] & MASK_SUB) != 0x80) {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Solution s;
    // vector<int> ss = {235, 140, 4};
    // vector<int> ss = {197, 130, 1};
    vector<int> ss = {240,162,138,147};
    bool ans = s.validUtf8(ss);
    cerr << ans << endl;
    return 0;
}

