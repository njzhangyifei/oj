struct node {
    int label;
    vector<node*> adj;
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<node*> nodes(numCourses, nullptr);
        for (int i = 0 ; i < numCourses; i++) {
            nodes[i] = new node();
            nodes[i]-> label = i;
        }

        vector<int> indeg(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int to = prerequisites[i].first;
            int from = prerequisites[i].second;
            nodes[from]->adj.push_back(nodes[to]);
            indeg[to] += 1;
        }

        vector<int> res;
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; ++j) {
                if (indeg[j] == 0) {
                    res.push_back(j);
                    break;
                }
            }
            if (j >= numCourses) {
                return vector<int>();
            }
            indeg[j] = -1;
            for (int k = 0; k < nodes[j]->adj.size(); ++k){
                indeg[nodes[j]->adj[k]->label] --;
            }
        }

        return res;
    }
};
