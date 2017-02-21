#include <cmath>
#include <cstdio>
#include <vector>
#include <cinttypes>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    uint16_t src;
    uint16_t dest;
    uint16_t weight;
} edge;

void solve(){
    int num_node, num_edge;
    cin >> num_node >> num_edge;
    edge edges[num_edge*2];
    int i, j;
    for (i = 0; i < num_edge; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        from--; to--;
        edges[2*i].src = from;
        edges[2*i].dest = to;
        edges[2*i].weight = weight;
        edges[2*i+1].src = to;
        edges[2*i+1].dest = from;
        edges[2*i+1].weight = weight;
    }

    int start_vertex;
    cin >> start_vertex;
    start_vertex--;

    int shortest_path[num_node];
    for (i = 0; i < num_node; ++i) {
        shortest_path[i] = INT_MAX;
    }
    shortest_path[start_vertex] = 0;

    for (i = 0; i <= num_node-1 ; ++i) {
        
        for (j = 0; j < 2*num_edge; ++j) {
            uint16_t u = edges[j].src;
            uint16_t v = edges[j].dest;
            uint16_t weight = edges[j].weight;
            if (shortest_path[u] != INT_MAX) {
                // have visited
                
                // calculate path distance to v
                int current_path = shortest_path[u] + weight;
                if (current_path < shortest_path[v]) {
                    shortest_path[v] = current_path;
                }
            }
        }
    }

    for (i = 0; i < 2*num_edge; ++i) {
        uint16_t u = edges[i].src;
        uint16_t v = edges[i].dest;
        uint16_t weight = edges[i].weight;
        if (shortest_path[u] != INT_MAX 
            && shortest_path[u] + weight < shortest_path[v]) {
            // ovrflow or negative edge
        }
    }
    
    for (i = 0; i < num_node; ++i) {
        if (i == start_vertex) {
            continue;
        }
        if (shortest_path[i] == INT_MAX) {
            shortest_path[i] = -1;
        }
        cout << shortest_path[i] << " ";
    }

    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int T = 0; 
    cin >> T;

    int i;
    for (i = 0; i < T; ++i) {
        solve();
        cout << endl;
    }

    return 0;
}

