#include <cmath>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    int64_t distance;
    int biker_index;
    int bike_index;

    edge(int64_t distance, int biker_index, int bike_index){
        this->distance = distance;
        this->bike_index = bike_index;
        this->biker_index = biker_index;
    }

    bool operator<(edge other) const
    {
        return this->distance < other.distance;
    }
};

struct coord{
    int x;
    int y;

    coord(int x, int y){
        this->x = x;
        this->y = y;
    }

    int64_t distance_square(coord to){
        int64_t x_diff = (to.x - this->x);
        int64_t y_diff = (to.y - this->y);
        int64_t dist_sq = x_diff * x_diff + y_diff * y_diff;
        return dist_sq;
    }
};

int bfs_update_residual(
        int ** graph, int * parent_node, bool * visited,
        int node_count, int source_index, int target_index
        ) 
{
    int i;
    // initialize visited and clear parent
    for (i = 0; i < node_count; ++i) {
        parent_node[i] = -1;
        visited[i] = false;
    }

    std::queue<int> to_visit;
    to_visit.push(source_index);
    visited[source_index] = true;
    
    while (to_visit.size()) {
        uint8_t should_terminate = 0;
        int next = to_visit.front();
        to_visit.pop();
        for (i = 0; i < node_count; ++i) {
            if (graph[next][i] > 0) {
                // edge from next to this node exists
                if (!visited[i]) {
                    // not visited
                    to_visit.push(i);
                    visited[i] = true;
                    parent_node[i] = next;
                    if (i == target_index) {
                        // sink found
                        should_terminate = 1;
                        break;
                    }
                }
            }
        }
        if (should_terminate) {
            break;
        }
    }

    int path_cap = INT_MAX;
    int path_pointer = target_index;
    while (parent_node[path_pointer] != -1) {
        int parent = parent_node[path_pointer];
        path_cap = min(path_cap, graph[parent][path_pointer]);
        path_pointer = parent;
    }

    if (path_cap == INT_MAX) {
        return 0;
    }

    // update residual graph
    path_pointer = target_index;
    while (parent_node[path_pointer] != -1) {
        int parent = parent_node[path_pointer];
        graph[parent][path_pointer] -= path_cap;
        graph[path_pointer][parent] += path_cap;
        path_pointer = parent;
    }

    return path_cap;
}

int max_flow(int ** graph , int node_count, int source_index, int target_index)
{
    int i;
    int ** residual_graph = new int * [node_count];
    for (i = 0; i < node_count; ++i) {
        residual_graph[i] = new int[node_count];
        memset(residual_graph[i], 0, node_count * sizeof(int));
    }

    int * parent_node = new int[node_count];
    memset(parent_node, 0, node_count * sizeof(int));

    bool * visited = new bool[node_count];
    for (i = 0; i < node_count; ++i) {
        visited[i] = false;
    }

    int maxflow = 0;
    while (true) {
        int path_cap = bfs_update_residual(graph, parent_node, visited, 
                node_count, source_index, target_index );
        if (path_cap == 0) {
            // no more augmenting path
            break;
        }
        maxflow += path_cap;
    }

    return maxflow;
}

int solve(
        int bikers_count, int bikes_count,
        vector<edge> * edges, int64_t distance_limit
        )
{
    // construct graph
    int node_count = bikers_count + bikes_count + 2; // add source and sink
    int source_index = node_count - 2;
    int target_index = node_count - 1;
    int i;
    int ** graph = new int * [node_count];
    for (i = 0; i < node_count; ++i) {
        graph[i] = new int[node_count];
        memset(graph[i], 0, node_count * sizeof(int));
    }

    // construct edges in graph
    for (i = 0; i < edges->size(); ++i) {
        edge e = edges->at(i);
        if (e.distance <= distance_limit) {
            // valid edge in graph
            graph[source_index][e.biker_index] = 1;
            graph[e.biker_index][e.bike_index + bikers_count] = 1; 
            graph[e.bike_index + bikers_count][target_index ] = 1;
        }
    }

    // perform maxflow
    int res = max_flow(graph, node_count, source_index, target_index);
    
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M, K;
    // N = bikers, M = bikes, K = limit
    cin >> N >> M >> K;

    int i, j;
    std::vector<coord> * bikers_coord = new vector<coord>();
    std::vector<coord> * bikes_coord = new vector<coord>();

    for (i = 0; i < N; ++i) {
        int x; int y;
        cin >> x >> y;
        bikers_coord->push_back(coord(x, y));
    }
    for (i = 0; i < M; ++i) {
        int x; int y;
        cin >> x >> y;
        bikes_coord->push_back(coord(x, y));
    }

    std::vector<edge> * edges = new std::vector<edge>();

    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            auto biker = (*bikers_coord)[i];
            auto bike = (*bikes_coord)[j];
            int64_t distance = biker.distance_square(bike);
            // prepare the edges 
            edges->push_back(edge(distance, i, j));
        }
    }

    sort(edges->begin(), edges->end());

    int ans_index = 0;
    int low = 0;
    int high = edges->size();
    while (low <= high) {
        int mid = (low+high) / 2;
        int64_t limit = (*edges)[mid].distance;
        cerr << "searching low = " << low << " high = " << high << " mid = " << mid << endl;
        int res = solve(N, M, edges, limit);
        cerr << "res = " << res << " w/ limit = " << limit << endl;
        ans_index = mid;

        if (res >= K){
            if (mid == 0) {
                break;
            }
            limit = (*edges)[mid - 1].distance;
            int prev_res = solve(N, M, edges, limit);
            if (prev_res < K) {
                break;
            }
        } 

        if (res >= K) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << (*edges)[ans_index].distance;

    return 0;
}

