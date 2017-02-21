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

std::vector<string> * split(string s, char delim){
    std::stringstream ss(s);
    auto v = new std::vector<string>();
    string e;
    while (getline(ss, e, delim)) {
        v->push_back(e);
    }
    return v;
}

struct node{
    int city_no;
    string city_name;
    std::vector<int> * v_adj = new vector<int>();

    int from;
    int to;

    node(int city_no, string city_name){
        this->city_no = city_no;
        this->city_name = city_name;
    }
};

bool cyclic_detection_util(
        int v, bool visited[], bool rec[],
        std::vector<node *> * v_node){
    if (visited[v] == false) {
        visited[v] = true;
        rec[v] = true;

        vector<int>::iterator iter;
        for (iter = v_node->at(v)->v_adj->begin(); 
              iter !=  v_node->at(v)->v_adj->end();
              iter ++) {
            if (!visited[*iter] && 
                    cyclic_detection_util(*iter, visited, rec, v_node)) {
                return true;
            } else if(rec[*iter]){
                return true;
            }
        }
    }
    rec[v] = false;
    return false;
}

void solve(){
    int i, j;
    int N;
    cin >> N;
    cin.get();

    std::map<string, int> * map_city = new map<string, int> ();
    std::vector<node *> * v_node = new vector<node *>();

    int city_no = 0;
    for (i = 0; i < N; ++i) {
        string s;
        std::getline(cin, s);
        auto v = split(s, ',');
        for (auto i : (*v)) {
            if (map_city->find(i) == map_city->end()) {
                map_city->insert(pair<string, int>(i, city_no));
                v_node->push_back(new node(city_no, i));
                city_no++;
            }
        }
        for (j = 0; j < (int)v->size()-1; ++j) {
            auto this_node = v_node->at(map_city->at(v->at(j)));
            auto next_node = v_node->at(map_city->at(v->at(j+1)));
            this_node->v_adj->push_back(next_node->city_no);
        }
        delete v;
    }

    #ifdef DEBUG
    cerr << "graph:" << endl;
    for (auto i : (*v_node)) {
        cerr << i->city_name << " adj ";
        for (auto e : (*(i->v_adj))) {
            cerr << v_node->at(e)->city_name << " ";
        }
        cerr << endl;
    }
    cerr << endl;
    #endif

    bool * visited = new bool[v_node->size()];
    bool * rec = new bool[v_node->size()];
    for (i = 0; i < v_node->size(); ++i) {
        visited[i] = false;
        rec[i] = false;
    }

    for (i = 0; i < v_node->size(); ++i) {
        if (cyclic_detection_util(i, visited, rec, v_node)) {
            cout << "ORDER VIOLATION" << endl;
            return;
        }
    }
    
    cout << "ORDER EXISTS" << endl;
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    int i;
    for (i = 0; i < T; ++i) {
        solve();
    }

    return 0;
}

