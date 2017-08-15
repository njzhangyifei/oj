#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool distanceOne(string w1, string w2){
            int dist = 0;
            for (int i = 0; i < w1.size(); ++i) {
                if (w1[i] != w2[i]) {
                    dist ++;
                }
            }
            return dist == 1;
        }

        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            int num_dict = wordList.size();
            bool visited[num_dict+1];
            int parent[num_dict+1];
            vector<int> map[num_dict+1];
            int end = -1;
            for (int i = 0; i < num_dict; ++i) {
                for (int j = i+1; j < num_dict; ++j) {
                    string w1 = wordList[i];
                    string w2 = wordList[j];
                    if (distanceOne(w1, w2)) {
                        map[i].push_back(j);
                        map[j].push_back(i);
                    }
                }
                if (distanceOne(wordList[i], beginWord)) {
                    map[i].push_back(num_dict); 
                    map[num_dict].push_back(i); 
                }
                visited[i] = false;
                parent[i] = -1;
                if (wordList[i] == endWord) {
                    end = i;
                }
            }
            visited[num_dict] = false;

            if (end == -1) {
                return 0;
            }

            queue<int> v;

            // cerr << "from " << num_dict << " to " << end << endl;
            bool found = false;
            v.push(num_dict);
            visited[num_dict] = true;
            while (v.size()) {
                int current = v.front();
                v.pop();
                // cerr << "visiting " << current << endl;
                if (current == end) {
                    found = true;
                    break;
                }
                for (auto i : map[current]) {
                    if (!visited[i]) { 
                        v.push(i);
                        visited[i] = true;
                        parent[i] = current;
                    }
                }
            }

            if (!found) {
                // cerr << "not found" << endl;
                return 0;
            }

            // for (int i = 0; i < num_dict+1; ++i) {
                // cerr << parent[i] << " ";
            // }
            // cerr << endl;
            int path_len = 1;
            while (true) {
                end = parent[end];
                path_len ++;
                if (end == num_dict) {
                    break;
                }
            }

            // cerr << path_len << endl;
            return path_len;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string begin = "hit";
    string end = "cog";
    vector<string> dict = {"hot","dot","dog","lot","log","cog"};
    Solution s;
    int ans = s.ladderLength(begin, end, dict);
    cerr << ans << endl;
    return 0;
}

