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

// #define DEBUG

using namespace std;

struct Query {
    int measure_key;
    int origin_key;
    
    Query(int measure_key, int origin_key){
        this->measure_key = measure_key;
        this->origin_key = origin_key;
    }
};

struct Node {
    int key;
    int parent;
    std::vector<Node *> * v_child;

    Node(int key){
        this->v_child = new std::vector<Node *>();
        this->key = key;
        this->parent = -1;
    }

    void append_child(Node * child){
        this->v_child->push_back(child);
    }
};

Node * lca (Node * a, Node * b, Node * root) {
    if (a == root || b == root) {
        return root;
    }

    Node * res = NULL;

    int node_found = 0;
    for (auto i : (*root->v_child)) {
        // do LCA on i
        Node * temp = lca(a, b, i);
        if (temp != NULL) {
            res = temp;
            node_found ++;
        }
        if (node_found >= 2) {
            return root;
        }
    }

    return res;
}

void print_nodes(vector<Node *> * v_nodes){
    #ifdef DEBUG
    for (auto node : (*v_nodes)) {
        cerr << "node " << node->key << " parent " << node->parent << ": ";
        for (auto child : (*node->v_child)) {
            cerr << child->key << " ";
        }
        cerr << endl;
    }
    #endif
}


int * from_parent_map;
void construct_from_parent_map(std::vector<Node *> * v_nodes){
    from_parent_map = new int  [v_nodes->size()] {0};

    std::queue<Node *> to_visit;
    to_visit.push(v_nodes->at(0)); // visit root first

    while (!to_visit.empty()) {
        auto next_node = to_visit.front();
        to_visit.pop();

        for (auto child_node : (*next_node->v_child)) {
            from_parent_map[child_node->key-1] = from_parent_map[next_node->key-1] + 1;
            to_visit.push(child_node);
        }
    }
    #ifdef DEBUG
    int i;
    cerr << "from_parent_map:"<< endl;
    for (i = 0; i < v_nodes->size(); ++i) {
        cerr << from_parent_map[i] << " "; 
    }
    cerr << endl;
    #endif
}

int path_from_parent
(Node * child, Node * parent, std::vector<Node *> * v_nodes) 
{
    if (child == parent) {
        return 0;
    }
    int distance_parent_root = from_parent_map[parent->key-1];
    int distance_child_root = from_parent_map[child->key-1];
    return (distance_child_root - distance_parent_root);
}

int calculate_gravity
(Node * origin_node, Node * measure_node, std::vector<Node *> * v_nodes) {
    Node * root_node = v_nodes->at(0);
    Node * lca_node = lca(origin_node, measure_node, root_node);
    int distance_origin_measure = 
        path_from_parent(measure_node, lca_node, v_nodes) +
        path_from_parent(origin_node, lca_node, v_nodes);

    int distance_child_sq_sum = 0;
    for (auto child_node : (*origin_node->v_child)) {
        int distance_child_sq_single = calculate_gravity(child_node, measure_node, v_nodes);
        distance_child_sq_sum += distance_child_sq_single;
    }
    int res = distance_child_sq_sum + distance_origin_measure * distance_origin_measure;
    #ifdef DEBUG
    cerr << "origin: " << origin_node->key 
        << " measure: " << measure_node->key 
        << " = " << res << endl;
    #endif
    return res;
}

int calculate_gravity_with_lca
(Node * origin_node, Node * measure_node, 
 Node * lca_node, 
 std::vector<Node *> * v_nodes) {
    int distance_origin_measure = 
        path_from_parent(measure_node, lca_node, v_nodes) +
        path_from_parent(origin_node, lca_node, v_nodes);
    int distance_child_sq_sum = 0;
    for (auto child_node : (*origin_node->v_child)) {
        int distance_child_sq_single = calculate_gravity_with_lca
            (child_node, measure_node, lca_node, v_nodes);
        distance_child_sq_sum += distance_child_sq_single;
    }
    int res = distance_child_sq_sum + distance_origin_measure * distance_origin_measure;
    #ifdef DEBUG
    cerr << "origin: " << origin_node->key 
        << " measure: " << measure_node->key 
        << " = " << res << endl;
    #endif
    return res;

}

void solve(std::vector<Node *> * v_nodes, std::vector<Query *> * v_queries){
    for (auto query : (*v_queries)) {
        // foreach query
        Node * root_node = v_nodes->at(0);
        Node * origin_node = v_nodes->at(query->origin_key - 1);
        Node * measure_node = v_nodes->at(query->measure_key - 1);
        Node * lca_node = lca(origin_node, measure_node, root_node);
        int res;
        if (lca_node == origin_node) {
            // in tree
            res = calculate_gravity(origin_node, measure_node, v_nodes);
        } else {
            // out of tree
            res = calculate_gravity_with_lca(origin_node, measure_node, lca_node, v_nodes);
        }
        cout << res << endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;

    int i;
    std::vector<Node *> * v_nodes = new std::vector<Node *>();
    for (i = 0; i < N; ++i) {
        v_nodes->push_back(new Node(i+1));
    }
    for (i = 1; i < N; ++i) {
        int parent;
        cin >> parent;
        auto child = v_nodes->at(i);
        child->parent = parent;
        v_nodes->at(parent-1)->append_child(child);
    }
    print_nodes(v_nodes);

    construct_from_parent_map(v_nodes);

    int N_experiments;
    cin >> N_experiments;
    std::vector<Query *> * v_queries = new std::vector<Query *>();
    for (i = 0; i < N_experiments; ++i) {
        int measure, turn_on;
        cin >> measure >> turn_on;
        v_queries->push_back(new Query(measure, turn_on));
    }

    solve(v_nodes, v_queries);
    return 0;
}

