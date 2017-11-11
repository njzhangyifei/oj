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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    std::vector<vector<int>> v;

    string s;
    while (getline(cin, s)) {
        std::stringstream ss(s);
        // cerr << "string = " << s << endl;
        std::vector<int> vv;
        int n;
        while (ss >> n) {
            vv.push_back(n);
        }
        v.push_back(vv);
    }

    int row = v.size();
    int col = v[0].size();

    std::vector<vector<int>> vT;
    for (int i = 0; i < col; ++i) {
        std::vector<int> vvvv(row);
        vT.push_back(vvvv);
    }

    int i, j;
    for(i = 0; i < v.size(); ++i) {
        for(j = 0; j < v[0].size(); ++j)
        {
            vT[j][i]=v[i][j];
        }
    }

    for (int i = 0; i < vT.size(); ++i) {
        for (int j = 0; j < vT[0].size(); ++j) {
            cout << vT[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

