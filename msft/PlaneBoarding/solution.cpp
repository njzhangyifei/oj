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
#include <stack>
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

struct person {
    int key;
    bool lazy;
    int row;
    int col;
    person(int key, bool l, int row, int col){
        lazy = l;
        this->key = key;
        this->row = row;
        this->col = col;
    }

};

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

    int n_row, n_col;
    int i, j, k;
    cin >> n_col >> n_row;


    int m_plane[n_row][n_col];
    for (i = 0; i < n_row; ++i) {
        for (j = 0; j < n_col; ++j) {
            m_plane[i][j] = -1;
        }
    }

    string s;
    cin >> s;

    std::vector<person *> v_person;

    auto s_array = split(s, ',');

    k = 0;
    for (auto i : (*s_array)) {
        int t_col = i[0] - 'A';
        i[0] = ' ';
        stringstream ss(i);
        int t_row;
        ss >> t_row;
        t_row-=1;
        bool lazy = (i[i.length()-1] == '*');
        v_person.push_back(new person(k++, lazy, t_row, t_col));
    }

    std::map<person *, std::vector<pair<int, int>> * > map_lazy_route;

    std::deque<person *> person_deque ;
    for (auto i : v_person) {
        person_deque.push_back(i);
        map_lazy_route[i] = new std::vector<pair<int,int>>();
    }
    while (!person_deque.empty()) {
        // get front
        auto current_person = person_deque.front();
        person_deque.pop_front();
        if (current_person->lazy) {
            for (i = 0; i < n_row; ++i) {
                bool done = false;
                for (j = 0; j < n_col; ++j) {
                    int person_in_seat = m_plane[i][j];
                    if (person_in_seat == -1) {
                        // no person in seat, take it
                        m_plane[i][j] = current_person->key;
                        map_lazy_route[current_person]->
                            push_back(pair<int,int>(j, i));
                        done = true;
                        break;
                    }
                }
                if (done) {
                    break;
                }
            }
        } else {
            // not lazy, move to seat
            int person_in_seat = m_plane[current_person->row][current_person->col];
            if (person_in_seat != -1) {
                // must be lazy
                person_deque.push_front(v_person[person_in_seat]);
            }
            m_plane[current_person->row][current_person->col] = 
                current_person->key;
        }
        // cerr << "running person" << current_person->key << 
            // (current_person->lazy ? "true" : "false") <<
            // current_person->row << ", "<< current_person->col

            // << endl;
    }


    int m,l;
    for (m = 0; m < v_person.size(); ++m) {
        if (v_person[m]->lazy) {
            auto i = map_lazy_route[v_person[m]];
            for (l = 0; l < i->size(); ++l) {
                auto item = i->at(l);
                cout << (char)('A'+item.first)<< 1+item.second;
                if (l==i->size()-1) {
                    // no comma
                } else {
                    cout << ",";
                }   
            }
            cout << endl;
        }
    }
    return 0;

}

