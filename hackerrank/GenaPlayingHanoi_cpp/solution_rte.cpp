#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

// #define DEBUG
//

bool greater_stack(const stack<int8_t> & lhs, const stack<int8_t> & rhs){
    return lhs.size() > rhs.size();
}

struct hanoi_state {
    std::vector<std::stack<int8_t>> pegs = vector<stack<int8_t>>(4);
    hanoi_state *   parent_state;

    // copy ctor
    hanoi_state(hanoi_state * state){
        pegs = state->pegs;
        parent_state = state->parent_state;
    }

    hanoi_state(vector<int> * config, hanoi_state * parent){
        int i;
        for (i = config->size() - 1; i >= 0; --i) {
            int peg = config->operator[](i) - 1;
#ifdef DEBUG
            cerr << "put " << i << " into " << peg << endl;
#endif
            this->pegs[peg].push(i);
        }
        parent_state = parent;
    }

    bool operator < (const hanoi_state & rhs) const {
        return std::tie(pegs[0], pegs[1], pegs[2], pegs[3]) <
            std::tie(rhs.pegs[0], rhs.pegs[1], rhs.pegs[2], rhs.pegs[3]);
    }

    bool operator == (const hanoi_state & rhs) const {
        return 
            (pegs[0] == rhs.pegs[0]) &&
            (pegs[1] == rhs.pegs[1]) &&
            (pegs[2] == rhs.pegs[2]) &&
            (pegs[3] == rhs.pegs[3]);
    }

    bool operator > (const hanoi_state & rhs) const {
        return std::tie(pegs[0], pegs[1], pegs[2], pegs[3]) >
            std::tie(rhs.pegs[0], rhs.pegs[1], rhs.pegs[2], rhs.pegs[3]);
    }

    void conduct_move(int from_peg, int to_peg){
        int8_t moved_disc = pegs[from_peg].top();
        pegs[from_peg].pop();
        pegs[to_peg].push(moved_disc);
    }

    bool valid_move(int from_peg, int to_peg){
        if (pegs[from_peg].size() == 0) {
            return false;
        }
        if (pegs[to_peg].size() == 0) {
            return true;
        }
        int moved_disc = pegs[from_peg].top();
        int dest_disc = pegs[to_peg].top();
        if (moved_disc < dest_disc) {
            return true;
        }
        return false;
    }

    bool is_initial_status(){
        if (pegs[1].size() == 0 && pegs[2].size() == 0 && pegs[3].size() == 0) {
            return true;
        }
        return false;
    }

    void sort_pegs(){
        sort(pegs.begin(), pegs.end(), greater_stack);
    }

    void print_internal(ostream& os){
        int i;
        for (i = 0; i < 4; ++i) {
            if (pegs[i].size()) {
                os << pegs[i].top();
            } else {
                os << "-";
            }
            os << ", ";
        }
        os << endl;
    }
};

ostream& operator<<(ostream& os, const hanoi_state & state)
{
    return os 
        << state.pegs[0].size() << ", "
        << state.pegs[1].size() << ", "
        << state.pegs[2].size() << ", "
        << state.pegs[3].size();
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int i, j;
    cin >> N;

    std::vector<int> * v_input = new std::vector<int>;

    for (i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        v_input->push_back(temp);
    }

    hanoi_state * initial_state = new hanoi_state(v_input, NULL);

    std::set<hanoi_state> * visited = new std::set<hanoi_state>;
    std::queue<hanoi_state *> * to_visit = new std::queue<hanoi_state *>;
    to_visit->push(initial_state);
    visited->insert(*initial_state);

    hanoi_state * final_state;

    bool found = false;
    while (to_visit->size() != 0) {
        auto current_state = to_visit->front();
        to_visit->pop();
#ifdef DEBUG
        cerr << "visiting : " << (*current_state) << endl;
        current_state->print_internal(cerr);
#endif

        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 4; ++j) {
                if (i == j) {
                    continue;
                }
                if (current_state->pegs[i].size() == 0) {
                    continue;
                }
                if (current_state->valid_move(i, j)) {
                    // a move from i to j is valid
                    hanoi_state * new_state = new hanoi_state(current_state);
                    new_state->conduct_move(i, j);
                    new_state->parent_state = current_state;
                    if (visited->find(*new_state) == visited->end()) {
                        // not visited
                        if (new_state->is_initial_status()) {
                            // we found it
                            found = true;
                            final_state = new_state;
#ifdef DEBUG
                            cerr << "found!" << endl;
#endif
                            break;
                        }
                        to_visit->push(new_state);
                        visited->insert(*current_state);
                    }
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            break;
        }
    }

    int steps = 0;
    while (final_state != initial_state) {
#ifdef DEBUG
        cerr << "visiting " << (*final_state) << endl;
#endif
        final_state = final_state->parent_state;
        steps ++;
    }

    cout << steps << endl;

    return 0;
}

