#include <cmath>
#include <cstdio>
#include <vector>
#include <cinttypes>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void solution(){
    int num_node, num_edge;
    cin >> num_node >> num_edge;
    uint8_t graph[num_node][num_node];
    memset(graph, 0, num_node * num_node * sizeof(uint8_t));
    int i;
    for (i = 0; i < num_edge; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from-1][to-1] = 6;
        graph[to-1][from-1] = 6;
    }

    int start_node;
    cin >> start_node;
    start_node --;

    std::queue<int> q;
    int path[num_node];
    memset(path, -1, num_node * sizeof(int));

    q.push(start_node);
    path[start_node] = 0;

    while (q.size()) {
        int current_node = q.front();
        q.pop();
        int i;
        int current_path = path[current_node];
        for (i = 0; i < num_node; ++i) {
            if (graph[current_node][i] && path[i] == -1) {
                // exists an edge, visit it visited next, update the path
                path[i] = current_path + graph[current_node][i];
                q.push(i);
            }
        }
    }

    for (i = 0; i < num_node; ++i) {
        if (i == start_node) {
            continue;
        }
        cout << path[i] << " ";
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
       solution();
    }

    return 0;
}
