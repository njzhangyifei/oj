#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;

    if (x1 == x2) {
        if (v1 == v2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        int shorter_x, shorter_v;
        int longer_x, longer_v;
        if (x1 < x2) {
            shorter_x = x1;   
            shorter_v = v1;
            longer_x = x2;
            longer_v = v2;
        } else {
            shorter_x = x2;   
            shorter_v = v2;
            longer_x = x1;
            longer_v = v1;
        }

        if (shorter_v < longer_v) {
            cout << "NO" << endl;
        } else {
            int v_diff = shorter_v - longer_v;
            int x_diff = longer_x - shorter_x;
            if (v_diff == 0) {
                cout << "NO" << endl;
            } else if (x_diff % v_diff == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

