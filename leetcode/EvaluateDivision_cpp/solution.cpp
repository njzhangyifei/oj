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

            if (queries.size() == 0 || equations.size() == 0) {
                return vector<double>();
            }

            std::map<string, node *> map_var;

            for (int i = 0; i < equations.size(); ++i) {
                auto eqn = equations[i];
                auto val = values[i];
                node * f = map_var[eqn.first]  ? map_var[eqn.first] : new node(eqn.first);
                node * t = map_var[eqn.second] ? map_var[eqn.second]: new node(eqn.second);
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

                if (from == NULL || to == NULL) {
                    ans.push_back(-1.0);
                    continue;
                }

                if (from == to) {
                    ans.push_back(1.0);
                    continue;
                }

                unordered_map<node *, bool> visited;
                stack<pair<node *, edge *>> s;
                std::map<node *, pair<node *, edge*>> parent;
                visited[from] = true;
                s.push(make_pair(from, (edge *)NULL));
                bool found = false;
                while (s.size()) {
                    pair<node *, edge *> current_p = s.top();
                    s.pop();
                    if (current_p.first == to) {
                        // found it !
                        found = true;
                        break;
                    }
                    bool children = false;
                    for (auto e : current_p.first->edges) {
                        node * v = e->to;
                        if (!visited[v]) {
                            parent[v] = make_pair(current_p.first, e);
                            s.push(make_pair(v, e));
                            visited[v] = true;
                            children = true;
                        }
                    }
                }

                if (!found) {
                    ans.push_back(-1);
                    continue;
                }

                // cerr << from->name << " / " << to->name << endl;
                double res = 1;
                while (from != to) {
                    auto n_p = parent[to];
                    auto weight = n_p.second ? n_p.second->weight : 1;
                    res *= weight;
                    to = n_p.first;
                    // cerr << n_p.first->name << endl;
                }
                // cerr << res << endl;
                ans.push_back(res);
            }
            return ans;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<pair<string, string>> equations = 
    {{"a","b"},{"e","f"},{"b","e"}};
    // { {"a","b"},{"b","c"} };
    vector<double> values = 
    {3.4,1.4,2.3};
    // {2.0,3.0};
    vector<pair<string, string>> queries = 
    {{"b","a"},{"a","f"},{"f","f"},{"e","e"},{"c","c"},{"a","c"},{"f","e"}};
    // { {"a","c"},{"b","c"},{"a","e"},{"a","a"},{"x","x"}, {"b","a"}};

    Solution s;
    s.calcEquation(equations, values, queries);
    return 0;
}

