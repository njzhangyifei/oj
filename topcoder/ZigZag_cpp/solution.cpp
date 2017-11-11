#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class ZigZag
{
public:
    int longestZigZag(vector<int> v){
        int element_num = v.size();
        int table[element_num][2];
        memset(table, 0, sizeof(int) * element_num * 2);

        table[0][0] = 1;
        table[0][1] = 1;
        int i,j;
        for (i = 1; i < element_num; ++i) {
            for (j = i-1; j >= 0; --j) {
                // for all length
                int diff = v[i] - v[j];
                if (diff < 0) {
                    // negative
                    table[i][0] = max(table[i][0], table[j][1] + 1);
                } else if (diff > 0){
                    table[i][1] = max(table[i][1], table[j][0] + 1);
                }
            }
        }

        int max = 1;
        for (i = 0; i < element_num; ++i) {
            if (table[i][0] > max) {
                max = table[i][0];
            }
            if (table[i][1] > max) {
                max = table[i][1];
            }
        }

        cout << " el ";
        for (i = 0; i < element_num; ++i) {
            cout << v[i] << "\t";
        }
        cout << endl;
        cout << " [0] ";
        for (i = 0; i < element_num; ++i) {
            cout << table[i][0] << "\t";
        }
        cout << endl;
        cout << " [1] ";
        for (i = 0; i < element_num; ++i) {
            cout << table[i][1] << "\t";
        }
        cout << endl;
        cout << max;
        return max;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // int t[] = { 1, 7, 4, 9, 2, 5 };
    int t[] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    
    std::vector<int> v;
    int i;
    for (i = 0; i < 10; ++i) {
        v.push_back(t[i]);
    }
    ZigZag zigzag;
    zigzag.longestZigZag(v);
    return 0;
}

