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

struct Node {
    vector<Node *> adj;
    int dist;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int SC;
    int SP;
    int MD;
    cin >> SP;
    cin >> SC;
    cin >> MD;

    int car_x, car_y;
    int person_x, person_y;
    cin >> car_x >> car_y;
    cin >> person_x >> person_y;

    int N, M;
    cin >> N >> M;

    Node* nodes[N][M];
    std::vector<Node *> v_nodes;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int t;
            cin >> t;
            Node * n = new Node();
            n->dist = t;
            nodes[i][j] = n;
        }
    }

    std::vector<pair<int, int>> direc = 
    {{0,1}, {0,-1}, {1,0}, {-1,0}};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int new_x = i;
            int new_y = j;
            for (auto d : direc) {
                new_x += d.first;
                new_y += d.second;
                if (new_x >= 0 && new_x < N
                    && new_y >= 0 && new_y < M
                        ) {
                    nodes[i][j]->adj.push_back(nodes[new_x][new_y]);
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::priority_queue<pair<int, Node *>,
                std::vector<pair<int, Node *>>, greater<pair<int, Node*>>> 
                    pq;;
            std::vector<vector<int>> dist;
            for (int i = 0; i < N; ++i) {
                dist.push_back(vector<int>());
                for (int j = 0; j < M; ++i) {
                    dist[i].push_back(INT_MAX);
                }   
            }

            pq.push(make_pair(0, nodes[i][j]));
            dist[i][j] = 
        }
    }



    return 0;



}

