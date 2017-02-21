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
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

#define BOARD_SIZE  (4)
#define IS_PIECE(x) (x == 'Q' || x == 'R' || x == 'B' || x == 'N')
#define IS_COLOR(x) (x != 0)
#define COLOR_WHITE (1)
#define COLOR_BLACK (2)
#define COLOR_INV(x) ((x==COLOR_WHITE) ? COLOR_BLACK : COLOR_WHITE)

using namespace std;

pair<int, int> operator + 
(const pair<int, int> & lhs, const pair<int, int> & rhs) 
{
    return pair<int, int>(lhs.first + rhs.first, lhs.second + rhs.second);
}

bool valid(const pair<int, int> t)
{
    if (t.first < 0 || t.first >= BOARD_SIZE) {
        return false;
    }
    if (t.second < 0 || t.second >= BOARD_SIZE) {
        return false;
    }
    return true;
}

std::map<char, std::vector<pair<int, int>> * > move_map;

void init_move_map(){
    int i;
    move_map['Q'] = new vector<pair<int, int>>();

    move_map['Q']->push_back(pair<int,int>( 0, 1));
    move_map['Q']->push_back(pair<int,int>( 1, 1));
    move_map['Q']->push_back(pair<int,int>(-1, 1));

    move_map['Q']->push_back(pair<int,int>( 1, 0));
    move_map['Q']->push_back(pair<int,int>(-1, 0));

    move_map['Q']->push_back(pair<int,int>( 0,-1));
    move_map['Q']->push_back(pair<int,int>( 1,-1));
    move_map['Q']->push_back(pair<int,int>(-1,-1));

    for (i = 1; i < 5; ++i) {
        move_map['Q']->push_back(pair<int,int>( i, 0));
        move_map['Q']->push_back(pair<int,int>(-i, 0));

        move_map['Q']->push_back(pair<int,int>( i, i));
        move_map['Q']->push_back(pair<int,int>(-i, i));
        move_map['Q']->push_back(pair<int,int>( i,-i));
        move_map['Q']->push_back(pair<int,int>(-i,-i));

        move_map['Q']->push_back(pair<int,int>( i, 0));
        move_map['Q']->push_back(pair<int,int>(-i, 0));
        move_map['Q']->push_back(pair<int,int>( 0, i));
        move_map['Q']->push_back(pair<int,int>( 0,-i));
    }

    move_map['N'] = new vector<pair<int, int>>();
    // knight moves
    move_map['N']->push_back(pair<int,int>(-2,  1));
    move_map['N']->push_back(pair<int,int>(-2, -1));
    move_map['N']->push_back(pair<int,int>(-1, -2));
    move_map['N']->push_back(pair<int,int>(-1,  2));
    move_map['N']->push_back(pair<int,int>( 2,  1));
    move_map['N']->push_back(pair<int,int>( 2, -1));
    move_map['N']->push_back(pair<int,int>( 1, -2));
    move_map['N']->push_back(pair<int,int>( 1,  2));

    move_map['B'] = new vector<pair<int, int>>();
    // bishop move
    for (i = 1; i < 5; ++i) {
        move_map['B']->push_back(pair<int,int>( i,  i));
        move_map['B']->push_back(pair<int,int>(-i, -i));
        move_map['B']->push_back(pair<int,int>( i, -i));
        move_map['B']->push_back(pair<int,int>(-i,  i));
    }

    move_map['R'] = new vector<pair<int, int>>();
    // rook move
    for (i = 0; i < 5; ++i) {
        move_map['R']->push_back(pair<int,int>( 0, i));
        move_map['R']->push_back(pair<int,int>( 0,-i));
        move_map['R']->push_back(pair<int,int>( i, 0));
        move_map['R']->push_back(pair<int,int>(-i, 0));
    }
}

struct chess_board {
    char    b[BOARD_SIZE][BOARD_SIZE];
    uint8_t c[BOARD_SIZE][BOARD_SIZE];

    chess_board(){
        memset(c, 0, sizeof(char) * BOARD_SIZE * BOARD_SIZE);
        memset(b, 0, sizeof(uint8_t) * BOARD_SIZE * BOARD_SIZE);
    }

    chess_board(chess_board * board){
        memcpy(c, board->c, sizeof(char) * BOARD_SIZE * BOARD_SIZE);
        memcpy(b, board->b, sizeof(uint8_t) * BOARD_SIZE * BOARD_SIZE);
    }

    void clear(){
        int i, j;
        for (i = 0; i < BOARD_SIZE; ++i) {
            for (j = 0; j < BOARD_SIZE; ++j) {
                if (c[i][j] == 'G' || c[i][j] == 'D') {
                    // no piece on this grid
                    c[i][j] = 0;
                }
            }
        }
    }
    
    void generate_valid_move(uint8_t color){
        // generate valid move
        auto new_board = new chess_board(this);
        new_board->clear();
        bool r = new_board->generate_checkmate_move(COLOR_INV(color));
        if (!r) {
            cerr << "GG" << endl;
        } else {
            cerr << "Game continues" << endl;
        }
    }
    
    bool generate_checkmate_move(uint8_t color){
        int i, j;
        bool rtnval = true; // true = alive
        for (i = 0; i < BOARD_SIZE; ++i) {
            for (j = 0; j < BOARD_SIZE; ++j) {
                if (color == c[i][j]) {
                    // generate move
                    auto pos = pair<int, int>(i, j);
                    for (auto move : (*move_map[color])) {
                        auto target = move+pos;
                        if (valid(target)) {
                            // dead, different color
                            if (c[target.first][target.second] != color) {
                                if (IS_PIECE(b[target.first][target.second])) {
                                    // gg, killed
                                    b[target.first][target.second] = 'G';
                                    rtnval = false;
                                } else {
                                    // death spot
                                    b[target.first][target.second] = 'D';
                                }
                            }
                        }
                    }
                }
            }
        }
        return rtnval;
    }

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

