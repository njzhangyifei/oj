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
        tree = new int64_t[size];
        memset(tree, 0, sizeof(int64_t) * size);
    };

    virtual ~binary_indexed_tree (){
        delete tree;
    };

    void set(int i, int64_t val) {
        while (i < size) {
            tree[i] += val;
            i += (i & -i);
        }
    }

    int64_t get(int i){
        int64_t res = 0;
        i = min(i, size-1);
        while (i > 0) {
            res += tree[i];
            i -= (i & -i);
        }
        return res;
    }

private:
    int size;
    int64_t * tree;
};

int64_t dfs(int current, binary_indexed_tree * tree, 
        vector<int> * map, int * parent, uint8_t * visited,
        int N, int K)
{
    visited[current] = 1;
    int64_t lower_bound = current - K;
    int64_t upper_bound_inc = current + K + 1;
    int64_t result = tree->get(upper_bound_inc) - tree->get(lower_bound);

    tree->set(current + 1, 1);
    for (auto i : map[current]) {
        if (!visited[i]) {
            result += dfs(i, tree, map, parent, visited, N, K);
        }
    }
    tree->set(current + 1, -1);

    return result;
}

int64_t solve(vector<int> * map, int * parent, int N, int K) {
    int i;

    // find root first
    int root;
    for (i = 0; i < N; ++i) {
        if (parent[i] == -1) {
            root = i;
        }
    }

    binary_indexed_tree t(100000 + 10);

    uint8_t * visited = new uint8_t[N];
    memset(visited, 0, N);

    int64_t res = dfs(root, &t, map, parent, visited, N, K);
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
    }   

    cout << solve(map, parent, N, K) << endl;

    return 0;
}

