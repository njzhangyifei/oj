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

int hanoi(int disk, int source, int dest, int spare){
    int counter = 0;
    if (disk == 0) {
        return 0;
    }
    counter = hanoi(disk-1, source, spare, dest);
    // move
    counter += 1;
    counter += hanoi(disk-1, spare, dest, source);
    return counter;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string input;
    while (getline(cin, input)) {
        auto v = split(input, ',');
        int a[3];
        int t = 0;
        for (auto i : (*v)) {
            stringstream ss(i);
            ss >>  a[t];
            t++;
        }
        if (a[1] == a[2]) {
            cout << 0 << endl;
        } else {
            int num = hanoi(a[0], 0, 1, 2);
            cout << num << endl;
        }
    }
    return 0;
}

