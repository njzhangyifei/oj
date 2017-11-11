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
#include <unordered_set>
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
            unordered_set<int> visited;
            
            std::stack<UndirectedGraphNode *> s;
            auto root = new UndirectedGraphNode(node->label);
            nodes[node->label] = root;
            s.push(node);
            visited.insert(node->label);
            while (s.size()) {
                UndirectedGraphNode * curr = s.top();
                UndirectedGraphNode * curr_clone = nodes[curr->label];
                s.pop();
                for (int i = 0; i < curr->neighbors.size(); ++i) {
                    UndirectedGraphNode * neigh = curr->neighbors[i];
                    UndirectedGraphNode * neigh_clone = NULL;
                    if (nodes.find(neigh->label) == nodes.end()) {
                        nodes[neigh->label] = new UndirectedGraphNode(neigh->label);
                    }
                    neigh_clone = nodes[neigh->label];
                    curr_clone->neighbors.push_back(neigh_clone);
                    if (visited.find(neigh->label) == visited.end()) {
                        s.push(neigh);
                        visited.insert(neigh->label);
                    }
                }
            }
            return root;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

