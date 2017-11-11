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

void solve(int caseno){
    int E, N;
    cin >> E;
    cin >> N;
    std::deque<int> rival;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        rival.push_back(temp);
    }

    sort(rival.begin(), rival.end());

    int honor = 0;
    for (int i = 0; i < rival.size(); ++i) {
        if (rival[i] < E) {
            E -= rival[i];
            honor ++;
        } else if (i < rival.size() - 1 && honor > 0) {
            E += rival[rival.size()-1];
            E -= rival[i];
            rival.pop_back();
        }
    }

    cout << "Case #" << caseno << ": " << honor << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve(i+1);
    }
 
    return 0;
}

