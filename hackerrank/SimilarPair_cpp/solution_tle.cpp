#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <set>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <cstring>
#include <algorithm>

// #define DEBUG

using namespace std;

class binary_indexed_tree
{
public:
    binary_indexed_tree (int size) : 
        size(size)
    {
        tree = new int[size];
        memset(tree, 0, sizeof(int) * size);
    };

    virtual ~binary_indexed_tree (){
        delete tree;
    };

    void set(int i, int val) {
        while (i < size) {
            tree[i] += val;
            i += (i & -i);
        }
    }

    int get(int i){
        int res = 0;
        i = min(i, size-1);
        while (i > 0) {
            // cerr << "i=" << i << endl;
            res += tree[i];
            i -= (i & -i);
        }
        return res;
    }

private:
    int size;
    int * tree;
};

int solve(vector<int> * map, int * parent, int N, int K) {
    int i;

    // find root first
    int root;
    for (i = 0; i < N; ++i) {
        if (parent[i] == -1) {
            root = i;
        }
    }

    uint8_t * visited = new uint8_t[N];
    memset(visited, 0, N);

    std::stack<int> next_visit;
    next_visit.push(root);
    visited[root] = 1;

        clock_t t_start = clock();
    int res = 0;
    while (next_visit.size()) {
        int current = next_visit.top();
        next_visit.pop();

        int current_parent = parent[current];

        binary_indexed_tree t(100000 + 10);
        while (current_parent != -1) {
            // not root
            t.set(current_parent+1, 1);
            current_parent = parent[current_parent];
        }
        int lower_bound = current - K;
        int upper_bound_inc = current + K + 1;
        res += t.get(upper_bound_inc) - t.get(lower_bound);

        #ifdef DEBUG
        cout << "visiting " << current << " , ancestor ";
        if (ancestors.size() == 0) {
            cout << "ROOT NODE";
        }
        for (auto i : ancestors) {
            cout << i << " ";
        }
        cout << endl;
        #endif

        for (auto i : map[current]) {
            if (!visited[i]) {
                // visit this next
                next_visit.push(i);
                visited[i] = 1;
            }
        }
    }

        fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - t_start)/CLOCKS_PER_SEC);
    return res;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, K;
    cin >> N >> K;

    int i;

    int * parent = new int[N];

    for (i = 0; i < N; ++i) {
        parent[i] = -1;
    }

    std::vector<int> * map = new vector<int>[N];

    for (i = 0; i < N-1; ++i) {
        int p;
        int c;
        cin >> p >> c;
        p--; c--;
        parent[c] = p;
        map[p].push_back(c);
        // map[c].push_back(p);
    }   

    cout << solve(map, parent, N, K) << endl;

    return 0;
}

