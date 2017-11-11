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


struct Node {
    string lib_name;
    std::vector<Node *> v_adj;

    Node (string name) {
        this->lib_name = name;
        v_adj = std::vector<Node *>();
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string target;
    cin >> target;
    int N;
    cin >> N;

    unoredered_map<string, Node*> nodes;
    for (int i = 0; i < N; ++i) {
        string lib;
        cin >> lib;
        int t;
        cin >> t;
        for (int j = 0; j < t; ++j) {
            string libs;
            cin >> libs;
            if (nodes.find(libs) == nodes.end()) {
                nodes.
            }
        }
    }
    return 0;
}

