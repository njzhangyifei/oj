#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if (node == NULL) {
                return NULL;
            }
            unordered_map<int, UndirectedGraphNode *> nodes;
            unordered_map<int, bool> visited;
            
            std::stack<UndirectedGraphNode *> s;
            auto root = new UndirectedGraphNode(node->label);
            nodes[node->label] = root;
            s.push(node);
            while (s.size()) {
                UndirectedGraphNode * curr = s.top();
                UndirectedGraphNode * curr_clone = nodes[curr->label];
                s.pop();
                for (int i = 0; i < curr->neighbors.size(); ++i) {
                    UndirectedGraphNode * neigh = curr->neighbors[i];
                    UndirectedGraphNode * neigh_clone = NULL;
                    if (nodes.find(neigh->label) == nodes.end()) {
                        nodes[neigh->label] = new UndirectedGraphNode(neigh->label);
                        // s.push(neigh);
                    } else {
                        neigh_clone = nodes[neigh->label];
                    }
                }
            }
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

