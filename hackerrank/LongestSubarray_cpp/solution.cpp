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

/*
 * Complete the function below.
 */
int maxLength(vector < int > a, int k) {
    int i; 
    int sum = a[0];
    int start_index = 0; // in
    int longest = 1;
    for (i = 1; i <= a.size(); ++i) { // length
        while (start_index < i-1 && sum > k)
        {
            sum -= a[start_index];
            start_index ++;
        }
        if (sum <= k) {
            longest = max(longest, (i-start_index));
            cerr << "valid length " << i << " starting " << start_index << endl;
        }
        if (i < a.size()) {
            sum += a[i];
        }
    }
    return longest;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    
    int _a_size = 0;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _a.push_back(_a_item);
    }
    
    int _k;
    cin >> _k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = maxLength(_a, _k);
    fout << res << endl;
    
    fout.close();
    return 0;
}

