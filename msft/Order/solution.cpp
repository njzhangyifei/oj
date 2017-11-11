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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N;
    cin >> N;

    int map[N][N];

    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            map[i][j] = 0;
        }
    }

    for (i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (j = 0; j < N; ++j) {
            if (s[j] == 'W') {
                // there is an edge from i to j
                map[j][i] = 1;
            }
        }
    }

    int last_team = -1;
    for (i = 0; i < N; ++i) {
        bool more_than_one = false;
        for (j = 0; j < N; ++j) {
            if (map[i][j]) {
                more_than_one = true;
            }
        }
        if (more_than_one) {
            continue;
        } else {
            // mark this as sink, last team
            last_team = i;
        }
    }

    // cout << last_team << endl;

    std::queue<int> q_visit;
    bool visited[N];
    for (i = 0; i < N; ++i) {
        visited[i] = false;
    }
    int source = last_team;
    q_visit.push(source);
    visited[source] = true;

    std::queue<int> q;
    while (!q_visit.empty()) {
        int current = q_visit.front();
        q_visit.pop();
        q.push(current);
        for (i = N-1; i >=0; i--) {
            if (map[i][current]) {
                if (!visited[i]) {
                    q_visit.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    while (!q.empty()) {
        cout << q.front()+ 1 << " ";
        q.pop();
    }


    return 0;
}

