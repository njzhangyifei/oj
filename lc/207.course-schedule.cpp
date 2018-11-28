

struct node {
    int label;
    vector<node *> adj;
};


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<node*> courses(numCourses, nullptr);

        for (int i = 0; i < numCourses; ++i) {
            courses[i] = new node();
            courses[i]->label = i;
        }

        for (int i = 0; i < prerequisites.size(); ++i) { 
            courses[prerequisites[i].second]->adj.push_back(courses[prerequisites[i].first]);
        }


        vector<bool> visited(numCourses, false);
        vector<bool> onpath(numCourses, false);

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) { 
                if (dfs(visited, onpath, courses[i])) {
                    return false;
                };
            }
        }

        return true;
    }

    bool dfs(vector<bool> & visited, vector<bool> & onpath, node * root) {
        onpath[root->label] = true;
        visited[root->label] = true;

        for (int i = 0; i < root->adj.size(); i++) {
            node * next = root->adj[i];

            if (onpath[next->label]) {
                return true;
            }

            if (!visited[next->label] && dfs(visited, onpath, next)) {
                return true;
            }
        }

        onpath[root->label] = false;

        return false;
    }
};
