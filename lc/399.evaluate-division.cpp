
struct node {
    string label;
    vector<pair<double, node *>> adj;

    node(string l) {
        label = l;
    }
};


class Solution {
public:

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, node*> nodes;
        for (int i = 0; i < equations.size(); ++i) {
            string from = equations[i].first;
            string to = equations[i].second;
            if (nodes.find(from) == nodes.end()) {
                nodes[from] = new node(from);
            }
            if (nodes.find(to) == nodes.end()) {
                nodes[to] = new node(to);
            }
            nodes[from]->adj.push_back(make_pair(values[i], nodes[to]));
            nodes[to]->adj.push_back(make_pair(1.0 / values[i], nodes[from]));
        }

        vector<double> res;
        for (int i = 0; i < queries.size(); ++i) {
            if (nodes.find(queries[i].first) == nodes.end() || 
                nodes.find(queries[i].second) == nodes.end()) {
                res.push_back(-1.0);
                continue;
            }

            node * q_from = nodes[queries[i].first];
            node * q_to = nodes[queries[i].second];

            std::stack<pair<double, node *>> q;
            q.push(make_pair(1.0, q_from));
            
            unordered_set<node*> visited;
            visited.insert(q_from);
            

            double ans = -1.0;
            while (!q.empty()) {
                auto route = q.top();
                double curr_val = route.first;
                node * curr = route.second;
                q.pop();
                if (curr == q_to) {
                    ans = curr_val;
                    break;
                }

                for (int i = 0; i < curr->adj.size(); ++i) {
                    auto edge = curr->adj[i];
                    double val = edge.first;
                    node * next = edge.second;
                    if (visited.find(next) == visited.end()) {
                        q.push(make_pair((val * curr_val), next));
                        visited.insert(next);
                    }
                }
            }

            res.push_back(ans);
        }
        return res;
    }
};
