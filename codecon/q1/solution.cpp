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

void display(deque<string> & t, deque<string> b) {
    cerr << "top ";
    for (auto i : t) {
        cerr << i << " ";
    }
    cerr << endl;
    cerr << "bot ";
    for (auto i : b) {
        cerr << i << " ";
    }
    cerr << endl;
}


void rotate(deque<string> & t, deque<string> & b, queue<string> & wait, string setter) {
    string ch = b.front();
    b.pop_front();
    t.push_front(ch);
    string out = t.back();
    t.pop_back();
    if (out == setter) {
        // do not get out
        b.push_back(out);
    } else {
        wait.push(out);
        b.push_back(wait.front());
        wait.pop();
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int count;
    cin >> count;

    string setter;
    cin >> setter;

    std::deque<string> top;
    std::deque<string> bottom;

    string s;
    cin >> s;
    bottom.push_front(s);
    cin >> s;
    top.push_front(s);
    cin >> s;
    top.push_front(s);
    cin >> s;
    top.push_front(s);
    string s_0, s_1;
    cin >> s_0;
    cin >> s_1;
    bottom.push_front(s_1);
    bottom.push_front(s_0);

    int waiting;
    cin >> waiting;
    std::queue<string> q;
    for (int i = 0; i < waiting; ++i) {
        string s;
        cin >> s;
        q.push(s);
    }

    for (int i = 0; i < count; ++i) {
        rotate(top, bottom, q, setter);
    }


    // display(top, bottom);
    cout << 
        bottom[2] << " " <<
        top[2]    << " "<<
        top[1]    << " "<<
        top[0]    << " "<<
        bottom[0] << " "<<
        bottom[1] <<endl;

    return 0;
}

