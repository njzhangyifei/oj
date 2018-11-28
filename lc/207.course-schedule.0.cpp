struct node
{
    int label;
    vector<node *> adj;
};

class Solution
{

  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<node *> courses(numCourses, nullptr);

        for (int i = 0; i < numCourses; ++i)
        {
            courses[i] = new node();
            courses[i]->label = i;
        }

        vector<int> indeg(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            courses[prerequisites[i].second]->adj.push_back(courses[prerequisites[i].first]);
            indeg[prerequisites[i].first] ++;
        }

        for (int i = 0; i < numCourses; ++i) {
            // go thru N times
            // first find indeg = 0
            int j = 0;
            for (; j < numCourses; ++j) {
                if (indeg[j] == 0) {
                    break;
                }
            }

            if (j == numCourses) {
                // not found
                return false;
            }

            indeg[j] = -1;
            for (int k = 0; k < courses[j]->adj.size(); ++k) {
                indeg[courses[j]->adj[k]->label] -= 1;
            }
        }

        return true;
    }
};
