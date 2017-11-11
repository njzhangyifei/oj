//
// .___  ___.  _______   ________   ________
// |   \/   | |       \ |       /  |       /
// |  \  /  | |  .--.  |`---/  /   `---/  /
// |  |\/|  | |  |  |  |   /  /       /  /
// |  |  |  | |  '--'  |  /  /----.  /  /----.
// |__|  |__| |_______/  /________| /________|
//
//

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
#include <sstream>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>


using namespace std;

// trim from left
inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}


// trim from right
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

std::vector<string> * split(string s, char delim){
    std::stringstream ss(s);
    auto v = new std::vector<string>();
    string e;
    while (getline(ss, e, delim)) {
        v->push_back(e);
    }
    return v;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */


    string s;
    getline(cin, s);
    string trimed = ltrim(s);
    auto t = split(trimed, ':');
    stringstream ss_0((*t)[0]);
    int output_node;
    ss_0 >> output_node;
    bool f = false;
    if ((*t)[1][0] == 'T') {
        f = true;
    }

    // cerr << output_node << " " << f << endl;

    vector<vector<string>> nodes;
    bool begin = false;
    while (getline(cin, s)){
        string trimed = ltrim(s);
        if (trimed.size() == 0) {
            continue;
        }
        if (trimed[0] == '[') {
            if (!begin) {
                begin = true;
                continue;
            } else {
                // start of a node
                vector<string> node;
                string node_s;
                while (getline(cin, node_s)) {
                    string node_trimed = rtrim(ltrim(node_s));
                    if (node_trimed[0] == ']') {
                        break;
                    }
                    node.push_back(node_trimed);
                }
                nodes.push_back(node);
            }
        }
    }

    vector<vector<string>> new_nodes;
    // remove whitespace
    int count = 0;
    vector<string> new_nodes_node;
    int empty_slot_count_orig = 0;
    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = 0; j < nodes[i].size(); ++j) {
            string s = nodes[i][j];
            if (s.size() > 0 || (!f)) {
                new_nodes_node.push_back(s);
                if (new_nodes_node.size() == output_node) {
                    new_nodes.push_back(new_nodes_node);
                    new_nodes_node.clear();
                }
            }
            if (s.size() == 0) {
                empty_slot_count_orig ++;
            }
        }
    }
    if (new_nodes_node.size()) {
        new_nodes.push_back(new_nodes_node);
    }

    while (new_nodes[new_nodes.size()-1].size() < output_node) {
        new_nodes[new_nodes.size()-1].push_back("");
    }

    int empty_slot_count_new =  0;
    for (int i = 0; i < new_nodes.size(); ++i) {
        for (int j = 0; j < new_nodes[i].size(); ++j) {
            string s = new_nodes[i][j];
            if (s.size() == 0) {
                empty_slot_count_new ++;
            }
        }
    }


    int output_node_count = new_nodes.size();
    int node_count_diff = output_node_count - nodes.size();
    int empty_slot_diff = empty_slot_count_new - empty_slot_count_orig;

    cout << output_node_count << endl;
    cout << node_count_diff << endl;
    cout << empty_slot_diff << endl;
    cout << empty_slot_count_new << endl;
    cout << "[" << endl;
    for (int i = 0; i < new_nodes.size(); ++i) {
        cout << "[" <<endl;
        for (int j = 0; j < output_node; ++j) {
            cout << new_nodes[i][j] << endl;
        }
        cout << "]" <<endl;
    }
    cout << "]" <<endl;
    cout << endl;

    return 0;
}

