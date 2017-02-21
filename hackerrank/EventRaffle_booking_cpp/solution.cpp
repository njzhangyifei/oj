#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;
struct event {
    int key;
    std::set<string> * passion = new std::set<string>();

    event(int k, istream & in){
        this->key = k;
        int n_passion;
        in >> n_passion;
        int i;
        for (i = 0; i < n_passion; ++i) {
            string temp;
            in >> temp;
            passion->insert(temp);
        }
    }
};

struct person {
    int key;
    int ticket;
    std::set<string> * passion = new std::set<string>();

    person(int k, istream & in){
        this->key = k;
        int n_passion;
        in >> ticket >> n_passion;
        int i;
        for (i = 0; i < n_passion; ++i) {
            string temp;
            in >> temp;
            passion->insert(temp);
        }
    }

    int match(event * e){
        set<string> intersect;
        set_intersection(
            passion->begin(),passion->end(),
            e->passion->begin(),e->passion->end(), 
            std::inserter(intersect,intersect.begin())
            );
        return intersect.size();
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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int i, j;
    cin >> N;

    std::vector<person *> * v_person = new vector<person *>();
    std::vector<event *> * v_event = new vector<event *>();
    for (i = 0; i < N; ++i) {
        v_person->push_back(new person(i, cin));
    }
    for (i = 0; i < N; ++i) {
        v_event->push_back(new event(i, cin));
    }

    int node_count = N + N + 2; // add source and sink
    int source_index = node_count - 2;
    int target_index = node_count - 1;
    int ** graph = new int * [node_count];
    for (i = 0; i < node_count; ++i) {
        graph[i] = new int[node_count];
        memset(graph[i], 0, node_count * sizeof(int));
    }

    for (i = 0; i < (int)v_person->size(); ++i) {
        for (j = 0; j < (int)v_event->size(); ++j) {
            // there is an edge when one passion matches
            auto person_ptr = v_person->at(i);
            auto event_ptr = v_event->at(j);
            graph[source_index][person_ptr->key] = 1;
            graph[person_ptr->key][event_ptr->key + N] = 
                person_ptr->match(event_ptr); 
            graph[event_ptr->key + N][target_index] = 1; 
        }
    }
    
    // perform maxflow
    int res = max_flow(graph, node_count, source_index, target_index);

    cout << res;

    return 0;
}

