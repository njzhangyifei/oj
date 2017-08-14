#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        struct edge;

        struct node {
            string name;
            std::vector<edge *> edges;

            node(string n){
                name =  n;
            }
        };

        struct edge {
            node * from;
            node * to;
            double weight;

            edge(node * f, node * t, double w){
                from = f; to = t; weight = w;
            }
        };

        vector<double> calcEquation(
                vector<pair<string, string>> equations, 
                vector<double>& values, 
                vector<pair<string, string>> queries) {

            std::map<string, node *> map_var;

            for (int i = 0; i < equations.size(); ++i) {
                auto eqn = equations[i];
                auto val = values[i];
                node * f = new node(eqn.first);
                node * t = new node(eqn.second);
                f->edges.push_back(new edge(f, t, val));
                t->edges.push_back(new edge(t, f, 1.0/val));
                map_var[eqn.first] = f;
                map_var[eqn.second] = t;
            }

            vector<double> ans;
            for (int i = 0; i < queries.size(); ++i) {
                auto query = queries[i];
                node * from = map_var[query.first];
                node * to = map_var[query.second];

                if (from == to) {
                    ans.push_back(1.0);
                    continue;
                }

                unordered_map<node *, bool> visited;
                stack<node *> s;
                visited[from] = true;
                s.push(from);
                while (s.size()) {
                    node * current = s.top();
                    s.pop();
                    if (current == to) {
                        // found it !
                    }
                    for (auto e : current->edges) {
                        node * v = e->to;
                        if (!visited[v]) {
                            s.push(v);
                            visited[v] = true;
                        }
                    }
                }
            }

            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

