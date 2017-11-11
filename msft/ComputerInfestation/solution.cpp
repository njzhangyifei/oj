//
// .___  ___.  _______   ________   ________  
// |   \/   | |       \ |       /  |       /  
// |  \  /  | |  .--.  |`---/  /   `---/  /   
// |  |\/|  | |  |  |  |   /  /       /  /    
// |  |  |  | |  '--'  |  /  /----.  /  /----.
// |__|  |__| |_______/  /________| /________|
//
//
                                           
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
#include <sstream>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

std::vector<string> * split(string s, char delim){
    std::stringstream ss(s);
    auto v = new std::vector<string>();
    string e;
    while (getline(ss, e, delim)) {
        v->push_back(e);
    }
    return v;
}

bool infected(vector<vector<bool>> & map, int i, int j, int len) {
    if (i < 0 || j < 0) {
        // healthy
        return false;
    }
    if (i >= len || j >= len) {
        return false;
    }
    return map[i][j];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    std::vector<vector<bool>> v;
    while (getline(cin, s)) {
        vector<bool> vv(s.length());
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                vv[i] = false;
            } else {
                vv[i] = true;
            }
        }
        v.push_back(vv);
    }

    int sz = v.size();

    while (true) {
        bool changed = false;

        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                // left
                if (v[i][j]) {
                    // infected;
                    continue;
                }
                bool left = infected(v, i, j-1, sz);
                bool right = infected(v, i, j+1, sz);
                bool up = infected(v, i-1, j, sz);
                bool down = infected(v, i+1, j, sz);

                if ((left + right + up + down) >= 2) {
                    // can infect
                    v[i][j] = true;
                    changed =true;
                }
            }
        }
        // cerr << "epoch" << endl;
        if (!changed) {
            break;
        }
    }

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            char c = '0';
            if (v[i][j]) {
                c = '1';
            }
            cout << c;
        }
        cout << endl;
    }

    return 0;
}

