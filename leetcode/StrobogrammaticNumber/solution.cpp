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
    bool isStrobogrammatic(string num) {
        vector<int> mapping(10, -1);
        mapping[0] = 0;
        mapping[1] = 1;
        mapping[8] = 8;
        mapping[9] = 6;
        mapping[6] = 9;
        int left = 0;
        int right = num.size() -1;
        while (left <= right) {
            if (
                    (mapping[num[left]-'0'] != -1 && mapping[num[right]-'0'] != -1)
                    &&
                    (mapping[num[left]-'0'] == num[right]-'0')
                
            ) {
                left ++;
                right --;
            } else {
                return false;
            }
        }
        return true;
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

