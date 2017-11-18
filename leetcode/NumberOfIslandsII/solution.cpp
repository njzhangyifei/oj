#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> rank;
    vector<int> parent;
    int n;

    UnionFind(int n){
        this->n = n;
        for (int i = 0; i < n; ++i) {
            rank.push_back(0);
            parent.push_back(i);
        }
    }

    int find(int idx) {
        if (parent[idx] != idx) {
            parent[idx] =  find(parent[idx]);
        }
        return parent[idx];
    }

    bool union2(int idx1, int idx2){
        int parent1 = find(idx1);
        int parent2 = find(idx2);
        if (parent2 == parent1) {
            return false;
        }
        int rank1 = rank[parent1];
        int rank2 = rank[parent2];
        if (rank1 < rank2) {
            parent[parent1] = parent2;
        } else {
            parent[parent2] = parent1;
            if (rank1 == rank2) {
                rank[parent1] ++;
            }
        }
        return true;
    }
    
};

class Solution {
    public:
        int convertIndex(int x, int y, int n){
            return x * n + y;
        }

        vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
            UnionFind * uf = new UnionFind(m*n);
            std::vector<vector<bool>> map 
                (m, vector<bool>(n, false));

            std::vector<pair<int, int>> dirs = 
            {
                {-1, 0},
                {1, 0},
                {0,-1},
                {0, 1},
            };
            vector<int> res;
            int count = 0;
            for (int i = 0; i < positions.size(); ++i) {
                count ++;
                for (int j = 0; j < dirs.size(); ++j) {
                    int xx = positions[i].first +  dirs[j].first;
                    int yy = positions[i].second + dirs[j].second;
                    if ((xx >= 0 && xx < m) &&
                        (yy >= 0 && yy < n)){
                        if (map[xx][yy]) {
                            // has island in there
                            bool merged = uf->union2(
                                    convertIndex(xx, yy, n),
                                    convertIndex(positions[i].first, positions[i].second, n)
                                );
                            if (merged) {
                                count --;
                            }
                        }
                    }
                }
                map[positions[i].first][positions[i].second] = true;
                res.push_back(count);
            }
            return res;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

