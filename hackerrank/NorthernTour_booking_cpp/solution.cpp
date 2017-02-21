#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <sstream>
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

struct city {
    int key;
    string name;
    int hours_required;
    std::vector<int> * v_adj = new vector<int>();

    city(string name, int hours_required){
        this->name = name;
        this->hours_required = hours_required;
    }
};

struct path {
    string city_a;
    string city_b;
    int time;

    path(string city_a, string city_b, int time){
        this->time = time;
        this->city_a = city_a;
        this->city_b = city_b;
    }
};

struct adj_node {
    int city_key;
    int weight;

    adj_node(int city_key, int weight){
        this->city_key = city_key;
        this->weight= weight;
    }
};

struct by_weight {
    bool operator()(adj_node & a, adj_node & b){
        return a.weight < b.weight;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    
    std::vector<city * > * v_city = new vector<city *>();
    std::vector<path * > * v_path = new vector<path *>();

    int i, j;
    for (i = 0; i < N; ++i) {
        string s;
        cin >> s;
        std::stringstream ss(s);
        string e;
        auto v = new std::vector<string>();
        while (getline(ss, e, ',')) {
            v->push_back(e);
        }
        std::stringstream se(v->at(1));
        int t;
        se >> t;
        auto c = new city(v->at(0), t);
        v_city->push_back(c);
        delete v;
    }
    v_city->push_back(new city("Bevagna", 0));

    int M;
    cin >> M;
    for (i = 0; i < M; ++i) {
        string s;
        cin >> s;
        std::stringstream ss(s);
        string e;
        auto v = new std::vector<string>();
        while (getline(ss, e, ',')) {
            v->push_back(e);
        }
        std::stringstream se(v->at(2));
        int t;
        se >> t;
        auto p = new path(v->at(0), v->at(1), t);
        v_path->push_back(p);
        delete v;
    }

    std::map<string, int> * city_map = new map<string,int>();
    for (i = 0; i < (int)v_city->size(); ++i) {
        auto city_ptr = v_city->at(i);
        city_ptr->key = i;
        city_map->insert(pair<string, int>(city_ptr->name, city_ptr->key));
        #ifdef DEBUG
        cerr << "city " << city_ptr->name 
            << " time " << city_ptr->hours_required << endl;
        #endif
    }

    int ** map = new int * [v_city->size()];
    for (i = 0; i < v_city->size(); ++i) {
        map[i] = new int[v_city->size()];
        memset(map[i], 0, sizeof(int) * (v_city->size()));
    }

    #ifdef DEBUG
    cerr << "allocating" << endl;
    #endif

    for (i = 0; i < (int)v_path->size(); ++i) {
        auto path_ptr = v_path->at(i);
        int a = city_map->at(path_ptr->city_a);
        int b = city_map->at(path_ptr->city_b);
        // adj list
        v_city->at(a)->v_adj->push_back(b);
        v_city->at(b)->v_adj->push_back(a);
        map[a][b] = path_ptr->time;
        map[b][a] = path_ptr->time;
    }

    int root_node = city_map->at("Bevagna");
    #ifdef DEBUG
    cerr << "root_node: " << root_node << endl;
    #endif

    bool * visited = new bool[v_city->size()];
    for (i = 0; i < (int)v_city->size(); ++i) {
        visited[i] = false;
    }

    std::vector<string> visiting_order;

    int remaining_day = 6 * (24-8);
    // bfs
    std::queue<int> * to_visit = new std::queue<int>();
    to_visit->push(root_node);
    visited[root_node] = true;
    while (to_visit->size() > 0) {
        // still able to make a visit
        int current_node = to_visit->front();
        auto current_node_ptr = v_city->at(current_node);
        visiting_order.push_back(current_node_ptr->name);
        to_visit->pop();

        std::vector<adj_node> v_adj_node_sorted;
        for (i = 0; i < (int)current_node_ptr->v_adj->size(); ++i) {
            int target_node = current_node_ptr->v_adj->at(i);
            int weight = 
                map[current_node][target_node] + 
                v_city->at(target_node)->hours_required;
            v_adj_node_sorted.push_back(adj_node(target_node, weight));
        }
        
        sort(v_adj_node_sorted.begin(), v_adj_node_sorted.end(), by_weight());

        #ifdef DEBUG
        cerr << "v_adj_node_sorted:" << endl;
        for (auto i : v_adj_node_sorted) {
            cerr << i.city_key << " w/ weight " << i.weight << endl;
        }
        #endif

        int next_visit_adj_node = -1;
        for (i = 0; i < (int)v_adj_node_sorted.size(); ++i) {
            int t = v_adj_node_sorted.at(i).city_key;
            if (!visited[t]) {
                next_visit_adj_node = i;
                break;
            } else {
                // next
                continue;
            }
        }

        if (next_visit_adj_node == -1) {
            break;
        }

        while (remaining_day > 0) {
            if (v_adj_node_sorted.at(next_visit_adj_node).weight > (24-8)) {
                // another day
                remaining_day -= (24-8);
                v_adj_node_sorted.at(next_visit_adj_node).weight -= (24-8);
            } else {
                remaining_day -= v_adj_node_sorted.at(next_visit_adj_node).weight;
                to_visit->push(v_adj_node_sorted.at(next_visit_adj_node).city_key);
                visited[v_adj_node_sorted.at(next_visit_adj_node).city_key] = true;
                break;
            }
        }
    }

    if (visiting_order.size() == 1) {
        cout << "NONE" << endl;
    }

    for (i = 1; i < visiting_order.size(); ++i) {
        cout << visiting_order.at(i) << endl;
    }

    return 0;
}

