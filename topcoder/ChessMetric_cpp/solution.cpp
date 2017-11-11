#include <cmath>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

// #define DEBUG
using namespace std;

class ChessMetric
{
public:
    void inline safe_fill(uint64_t *** board, int size, 
            int x, int y, int epoch, uint64_t d) {
        if (x < 0 || x >= size) {
            // over
            return;
        }
        if (y < 0 || y >= size) {
            // over
            return;
        }
        board[x][y][epoch] += d;
    }

    uint64_t inline safe_access(uint64_t *** board, int size, 
            int x, int y, int epoch) {
        if (x < 0 || x >= size) {
            // over
            return 0;
        }
        if (y < 0 || y >= size) {
            // over
            return 0;
        }
        return board[x][y][epoch];
    }

    void create_pattern(uintmax_t *** board, int size,
            int x, int y, int current_epoch) {
        uint64_t ways_to_current = safe_access(board, size, x, y, current_epoch);
        if (ways_to_current == 0) {
            // we do nothing
            return;
        }
        int new_epoch = current_epoch + 1;
        #define FILL(x,y,e,d) {safe_fill(board,size, x, y, e, d);}
        FILL(x-1,y-2,new_epoch, ways_to_current);
        FILL(x-2,y-1,new_epoch, ways_to_current);
        FILL(x-1,y-1,new_epoch, ways_to_current);
        FILL(x-1,y  ,new_epoch, ways_to_current);
        FILL(x-1,y+1,new_epoch, ways_to_current);
        FILL(x-1,y+2,new_epoch, ways_to_current);
        FILL(x-2,y+1,new_epoch, ways_to_current);
        FILL(x  ,y+1,new_epoch, ways_to_current);
        FILL(x  ,y-1,new_epoch, ways_to_current);
        FILL(x+1,y-1,new_epoch, ways_to_current);
        FILL(x+1,y-2,new_epoch, ways_to_current);
        FILL(x+2,y-1,new_epoch, ways_to_current);
        FILL(x+1,y  ,new_epoch, ways_to_current);
        FILL(x+1,y+1,new_epoch, ways_to_current);
        FILL(x+2,y+1,new_epoch, ways_to_current);
        FILL(x+1,y+2,new_epoch, ways_to_current);
        #undef FILL
    }

    void print_board(uint64_t *** board, int size, int epoch){
        #ifdef DEBUG
        int i, j;
        cout << "board at epoch " << epoch << endl;
        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                cout << board[i][j][epoch] << " ";
            }
            cout << endl;
        }
        #endif
    }

    long long howMany(int size, vector<int> start, vector<int> end, int numMoves) {
        uint64_t *** board = new uint64_t ** [size];
        int i, j, k;
        for (i = 0; i < size; ++i) {
            board[i] = new uint64_t * [size];
            for (j = 0; j < size; ++j) {
                board[i][j] = new uint64_t [51];
                memset(board[i][j], 0, sizeof(uint64_t) * 51);
            }
        }

        board[start[0]][start[1]][0] = 1;

        for (i = 1; i <= numMoves; ++i) {
            #ifdef DEBUG
            cout << " -- Epoch " << i << endl;
            #endif
            for (j = 0; j < size; ++j) {
                for (k = 0; k < size; ++k) {
                    create_pattern(board, size, j, k, i-1);
                }
            }
            print_board(board, size, i);
        }

        uint64_t res = board[end[0]][end[1]][numMoves];
        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                delete board[i][j];
            }
            delete board[i];
        }
        delete board;

        return res;
    }

private:
    /* data */
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    string s;
    stringstream ss;
    getline(cin, s);
    ss.str(s);
    ss.clear();

    ss >> T;

    int i;
    for (i = 0; i < T; ++i) {
        int size;
        std::vector<int> start;
        std::vector<int> end;

        getline(cin, s);
        ss.str(s);
        ss.clear();
        ss >> size;

        int x, y;

        getline(cin, s);
        ss.str(s);
        ss.clear();
        ss >> x >> y;
        start.push_back(x); 
        start.push_back(y); 

        getline(cin, s);
        ss.str(s);
        ss.clear();
        ss >> x >> y;
        end.push_back(x); 
        end.push_back(y); 

        int steps;
        getline(cin, s);
        ss.str(s);
        ss.clear();
        ss >> steps;

        cout << "-----------------------------------------------" << endl;
        cout << " * size: " << size << endl;
        cout << " * start: " << start[0] << "," << start[1] 
            << " - end: " << end[0] << "," << end[1] << endl;

        uint64_t ans;
        getline(cin, s);
        ss.str(s);
        ss.clear();
        ss >> ans;

        getline(cin, s);

        ChessMetric cm;
        uint64_t user_ans = cm.howMany(size, start, end, steps);

        cout << " * answer: " << ans << endl;
        cout << " * user ans: " << user_ans << endl;
        cout << ((ans==user_ans) ? "PASSED" : "FAILED") << endl;

    }

    return 0;
}

