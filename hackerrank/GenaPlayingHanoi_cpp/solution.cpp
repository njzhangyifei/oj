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

#define NUM_PEGS   (4)

uint64_t division_table[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000,
    100000000000,
    1000000000000,
    10000000000000,
};

uint64_t change_digit(uint64_t original, unsigned int digit, unsigned int num){
    digit ++;
    uint64_t left = original / division_table[digit];
    uint64_t right = original % division_table[digit-1];
    return left * division_table[digit] + num * division_table[digit-1] + right;
}

unsigned int get_digit(uint64_t original, unsigned int digit) {
    digit ++;
    uint64_t larger = original % division_table[digit];
    uint64_t right = original % division_table[digit-1];
    return ((larger - right) / division_table[digit-1]);
}

unsigned int top_for_peg(uint64_t state, unsigned int peg) {
    int i;
    for (i = 0; i < 10; ++i) {
        if (get_digit(state, i) == peg) {
            return i;
        }
    }
    return UINT_MAX; // empty
}

uint64_t conduct_move(uint64_t state, unsigned int top_for_peg_src_disc, unsigned int peg_dest) {
    return change_digit(state, top_for_peg_src_disc, peg_dest);
}

bool is_valid_move(unsigned int top_for_peg_src, unsigned int top_for_peg_dest){
    if (top_for_peg_src == UINT_MAX) {
        return false;
    }
    if (top_for_peg_dest == UINT_MAX) {
        return true;
    }
    if (top_for_peg_dest > top_for_peg_src) {
        return true;
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int i, j;
    cin >> N;

    std::vector<int> * v_input = new std::vector<int>;

    uint64_t initial_state = 0;
    uint64_t final_state = 0;

    for (i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        v_input->push_back(temp);
        initial_state = change_digit(initial_state, i, temp);
        final_state = change_digit(final_state, i, 1);
    }
    
    #ifdef DEBUG
    cerr << "initial_state: " << initial_state << endl;
    cerr << "final_state: " << final_state << endl;
    #endif

    std::queue<uint64_t> to_visit;
    std::map<uint64_t, uint64_t> parent_map;
    to_visit.push(initial_state);
    parent_map.insert(pair<uint64_t, uint64_t>(initial_state, UINT_MAX));

    bool found = false;
    while (to_visit.size() > 0) {
        uint64_t current_state = to_visit.front();
        to_visit.pop();

        #ifdef DEBUG
        cerr << "visiting " << current_state << endl;
        #endif

        int top_for_pegs[NUM_PEGS+1];
        for (i = 1; i <= NUM_PEGS; ++i) {
            top_for_pegs[i] = top_for_peg(current_state, i);
        }

        for (i = 1; i <= NUM_PEGS; ++i) {
            for (j = 1; j <= NUM_PEGS; ++j) {
                if (!is_valid_move(top_for_pegs[i],top_for_pegs[j])) {
                    // not valid move
                    continue;
                }
                uint64_t moved = conduct_move(current_state, top_for_pegs[i], j);
                if (parent_map.find(moved) == parent_map.end()) {
                    // not visited
                    to_visit.push(moved);
                    parent_map.insert(pair<uint64_t, uint64_t>(moved, current_state));
                    if (moved == final_state) {
                        // initial found
                        #ifdef DEBUG
                        cerr << "found! " << moved;
                        #endif
                        found = true;
                        break;
                    }
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
        final_state = parent_map[final_state];
        steps += 1;
    }

    cout << steps << endl;

    return 0;
}

