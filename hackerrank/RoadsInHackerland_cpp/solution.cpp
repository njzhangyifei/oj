#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <memory>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG

struct vertex {
    int key;
    vertex * parent;
    std::unique_ptr<std::vector<vertex *>> v_adj = 
        std::unique_ptr<std::vector<vertex *>>(new vector<vertex *>());
    
    vertex(int key){
        this->parent = NULL;
        this->key = key;
    }
};

struct edge {
    int from;
    int to;
    int weight;

    edge(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

ostream & operator << (ostream & os, const vertex & v){
    os << "vertex " << v.key;
    size_t i;
    os << " adj: ";
    for (i = 0; i < v.v_adj->size() - 1; ++i) {
        os << v.v_adj->operator[](i)->key;
        os << " ";
    }
    return os << v.v_adj->operator[](v.v_adj->size() - 1)->key;
}

ostream & operator << (ostream & os, const edge & e){
    return os << "from " << e.from << " to " << e.to << " w/ weight" << e.weight;
}

struct disjoint_set_element{
    int key;
    int parent;
    int rank;

    disjoint_set_element(int key){
        this->key = key;
        this->parent = key;
        this->rank = 0;
    }
}; 

struct disjoint_set{
    std::map<int, disjoint_set_element *> * disjoint_set_map;

    disjoint_set(){
        disjoint_set_map = new std::map<int, disjoint_set_element *>();
    }

    void make_set(int key){
        disjoint_set_map->insert(
                pair<int, disjoint_set_element *>(key, 
                    new disjoint_set_element(key)));
    }

    int find_set(int key){
        disjoint_set_element * element = disjoint_set_map->operator[](key);
        if (element->parent == key) {
            return key;
        }
        return find_set(element->parent);
    }

    void merge(int first, int second){
        int root_first = find_set(first);
        int root_second = find_set(second);

        if (root_first == root_second) {
            return;
        }

        disjoint_set_element * root_element_first = 
            disjoint_set_map->operator[](root_first);
        disjoint_set_element * root_element_second = 
            disjoint_set_map->operator[](root_second);

        if (root_element_first->rank < root_element_second->rank) {
            root_element_first->parent = root_element_second->key;
        } else if (root_element_first->rank > root_element_second->rank) {
            root_element_second->parent = root_element_first->key;
        } else {
            root_element_second->parent = root_element_first->key;
            root_element_first->rank = root_element_first->rank + 1;
        }
    }
};

bool weight_less_than(const edge * lhs, const edge * rhs){
    return lhs->weight < rhs->weight;
}

std::vector<edge *> * kruskal(vector<edge*> * edges, std::set<int> * v){
    disjoint_set * disjoint = new disjoint_set();
    std::vector<edge *> * sorted_edges = new vector<edge *>((*edges));
    std::vector<edge *> * mst = new vector<edge *>();

    sort(sorted_edges->begin(), sorted_edges->end(), weight_less_than);

    #ifdef DEBUG
    cerr << "sorted_edges:" << endl;
    for (auto i : (*sorted_edges)) {
        cerr << (*i) << endl;
    }
    #endif

    for (auto i : (*v)) {
        disjoint->make_set(i);
    }

    for (auto i : (*sorted_edges)) {
        if (disjoint->find_set(i->from) != disjoint->find_set(i->to)) {
            mst->push_back(i);
            disjoint->merge(i->from, i->to);
        }
    }

    delete sorted_edges;
    delete disjoint;

    return mst;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N, M;

    cin >> N >> M;

    std::vector<edge *> * v_edges = new std::vector<edge *>();
    std::set<int> * s_vertices = new std::set<int>();

    int i;
    for (i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        v_edges->push_back(new edge(A, B, C));
        s_vertices->insert(A);
        s_vertices->insert(B);
    }
    
    std::vector<edge *> * mst = kruskal(v_edges, s_vertices);

    std::set<vertex *> * s_mst_vertices = new std::set<vertex *>();

    #ifdef DEBUG
    cerr << "minimum spanning tree:" << endl;
    for (auto i : (*mst)) {
        cerr << (*i) << endl;
    }
    #endif
    
    std::map<int, vertex *> * m_vertices = new std::map<int, vertex*>();
    for (auto i : (*mst)) {
        s_mst_vertices->insert(new vertex(i->from));
        s_mst_vertices->insert(new vertex(i->to));
    }
    for (auto i : (*s_mst_vertices)) {
        m_vertices->insert(pair<int, vertex *>(i->key, i));
    }
    for (auto i : (*mst)) {
        auto to_ptr = m_vertices->operator[](i->to);
        auto from_ptr = m_vertices->operator[](i->from);
        to_ptr->v_adj->push_back(from_ptr);
        from_ptr->v_adj->push_back(to_ptr);
    }

    #ifdef DEBUG
    cerr << "m_vertices:" << endl;
    for (auto i : (*m_vertices)) {
        cerr << (*(i.second)) << endl;
    }
    #endif

    int sum = 0;

    cout << sum << endl;

    for (auto i : (*v_edges)) {
        delete i;
    }
    delete v_edges;
    return 0;
}

