#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int dfs_recur(int current, uint8_t * visited, int * weight_sum,
        int node_num, std::vector<std::vector<int>> * map, int * weight){
    visited[current] = true;
    int sum = weight[current]; 
    for (auto i : (*map)[current]) {
        if (!visited[i]) {
            // not visited
            sum += dfs_recur(i, visited, weight_sum, node_num, map, weight);
        }
    }
    weight_sum[current] = sum;
    return sum;
}

// int dfs(uint8_t * visited, int * weight_sum,
        // int node_num, std::vector<std::vector<int>> * map, int * weight){
    // std::stack<int> * s = new std::stack<int>();
    // int * parent = new int[node_num];
    // int i;

    // s->push(0);
    // parent[0] = -1; // root node doesn't have a parent

    // for (i = 0; i < node_num; ++i) {
        // weight_sum[i] = weight[i];
    // }

    // while (!s->empty()) {
        // int current = s->top();

        // int parent_index = parent[current]; 
        // while (parent_index != -1) {
            // weight_sum[parent_index] += weight[current];
            // parent_index = parent[parent_index];
        // }
        // s->pop();
        // for (auto i : (*map)[current]) {
            // if (!visited[i]) {
                // // not visited, visit next
                // visited[current] = true;
                // parent[i] = current;
                // s->push(i);
            // }
        // }
    // }

    // delete s;
    // return 0;
// }

int min_tree_diff(int node_num, std::vector<std::vector<int>> * map, int * weight){
    int total_weight = 0;
    int i;
    for (i = 0; i < node_num; ++i) {
        total_weight += weight[i];
    }

    uint8_t * visited = new uint8_t[node_num];
    memset(visited, 0, node_num);

    int * weight_sum = new int[node_num];
    memset(weight_sum, 0, (sizeof(int) * node_num));
    
    dfs_recur(0, visited, weight_sum, node_num, map, weight);
    // dfs(visited, weight_sum, node_num, map, weight);

    // cout << endl;
    // for (i = 0; i < node_num; ++i) {
        // cout << weight_sum[i] << " ";
    // }
    // cout << endl;
    
    int min_diff = INT_MAX;
    for (i = 0; i < node_num; ++i) {
        int sum_till_node = weight_sum[i];
        int sum_others = total_weight - sum_till_node;
        if (abs(sum_others - sum_till_node) < min_diff) {
            min_diff = abs(sum_others-sum_till_node);
        }
    }

    return min_diff;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int i;
    int node_num;
    cin >> node_num;
    
    // Create the map
    std::vector<std::vector<int>> * map = new std::vector<std::vector<int>>();
    for (i = 0; i < node_num; ++i) {
        map->push_back(std::vector<int>());
    }

    int * node_weight = new int [node_num];
    for (i = 0; i < node_num; ++i) {
        int weight;
        cin >> weight;
        node_weight[i] = weight;
    }

    for (i = 0; i < node_num-1; ++i) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        map->at(from).push_back(to);
        map->at(to).push_back(from);
    }

    int ans = min_tree_diff(node_num, map, node_weight);
    cout << ans << endl;

    return 0;
}

