/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return nullptr;
        }
        unordered_map<int, UndirectedGraphNode*> nodes;
        std::queue<UndirectedGraphNode *> q;

        UndirectedGraphNode * root = new UndirectedGraphNode(node->label);
        nodes[node->label] = root;

        for (int i = 0; i < node->neighbors.size(); ++i) {
            UndirectedGraphNode * next = node->neighbors[i];
            if (nodes.find(next->label) == nodes.end()) {
                UndirectedGraphNode * next_c = new UndirectedGraphNode(next->label);
                nodes[next->label] = next_c;
                q.push(next);
            }
            nodes[node->label]->neighbors.push_back(nodes[next->label]);
        }

        while (!q.empty()) {
            UndirectedGraphNode * node = q.front();
            q.pop();

            for (int i = 0; i < node->neighbors.size(); ++i) {
                UndirectedGraphNode * next = node->neighbors[i];
                if (nodes.find(next->label) == nodes.end()) {
                    UndirectedGraphNode * next_c = new UndirectedGraphNode(next->label);
                    nodes[next->label] = next_c;
                q.push(next);
                }
                nodes[node->label]->neighbors.push_back(nodes[next->label]);
            }
        }

        return root;


    }
};
