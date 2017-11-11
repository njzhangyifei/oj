#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <sstream>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG

#define PATH_FROM_LEFT  (1<<0)
#define PATH_FROM_DOWN  (1<<1)

class AvoidRoads
{
public:
    long long numWays(int width, int height, vector<string> bad) {
        width ++; height++;
            
        int i, j, k;
        uint8_t ** map = new uint8_t * [width]; 
        for (i = 0; i < width; ++i) {
            map[i] = new uint8_t[height];
            memset(map[i], 0, height);
        }

        for (i = 0; i < width; ++i) {
            for (j = 0; j < height; ++j) {
                uint8_t path_avail = PATH_FROM_LEFT | PATH_FROM_DOWN;
                if (i == 0) {
                    path_avail &= ~(PATH_FROM_LEFT);
                }
                if (j == 0) {
                    path_avail &= ~(PATH_FROM_DOWN);
                }
                map[i][j] = path_avail;
            }
        }

        for (auto bad_str: bad) {
            stringstream ss(bad_str);
            int width_1, height_1;
            int width_2, height_2;
            ss >> width_1 >> height_1 >> width_2 >> height_2;
            if (width_1 < width_2) {
                // left for width 2
                map[width_2][height_2] &= ~(PATH_FROM_LEFT);
            } else if (width_1 > width_2) {
                // left for width 1
                map[width_1][height_1] &= ~(PATH_FROM_LEFT);
            } else if (height_1 < height_2) {
                // down for height 2
                map[width_2][height_2] &= ~(PATH_FROM_DOWN);
            } else if (height_1 > height_2) {
                // down for height 1
                map[width_1][height_1] &= ~(PATH_FROM_DOWN);
            }
        }


        #ifdef DEBUG
        cout << "map:" << endl;
        for (i = height-1; i >= 0; --i) {
            cout << "[" << i << "] ";
            for (j = 0; j < width; ++j) {
                cout << (unsigned int)map[j][i] << " ";
            }
            cout << endl;
        }
        #endif

        uint64_t ** count = new uint64_t * [width]; 
        for (i = 0; i < width; ++i) {
            count[i] = new uint64_t[height];
            memset(count[i], 0, height * sizeof(uint64_t));
        }

        std::queue<pair<int,int>> q;
        for (i = 0; i < width+height; ++i) {
            int x = i;
            int y = 0;
            for (j = 0; j <= i; ++j) {
                if (x < 0 || y < 0 || x >= width || y >= height) {
                    x --;
                    y ++;
                    continue;
                }
                q.push(pair<int,int>(x,y));
                x --;
                y ++;
            }
        }

        while (q.size()) {
            pair<int,int> p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second; 
        // int x;
        // int y;
        // for (y = 0; y < height; ++y) {
            // for (x = 0; x < width; ++x) {
            if (x == 0 && y == 0) {
                count[x][y] = 1;
                continue;
            }

            #ifdef DEBUG
            cout << "visiting " << x << "," << y << " - ";
            #endif

            uint64_t temp_count = 0;
            if (map[x][y] & PATH_FROM_DOWN) {
                // has a path from down
                temp_count += count[x][y-1];
            #ifdef DEBUG
                cout << "d-ok ";
            #endif
            }
            if (map[x][y] & PATH_FROM_LEFT) {
                // has a path from left
                temp_count += count[x-1][y];
            #ifdef DEBUG
                cout << "l-ok ";
            #endif
            }
            #ifdef DEBUG
            cout << "count=" <<temp_count << endl;
            #endif
            count[x][y] = temp_count;
            // }
        }

        #ifdef DEBUG
        cout << "count:" << endl;
        for (i = height-1; i >= 0; --i) {
            cout << "[" << i << "] ";
            for (j = 0; j < width; ++j) {
                cout << count[j][i] << " ";
            }
            cout << endl;
        }
        #endif

        long long res = count[width-1][height-1];
        // free up mem
        for (i = 0; i < width; ++i) {
            delete map[i];
            delete count[i];
        }
        delete count;
        delete map;

        return res;
    }

private:
    /* data */
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    int i;

    string s;
    stringstream ss;
    getline(cin, s);
    ss.str(s);
    ss.clear();

    ss >> T;

    AvoidRoads avoidRoads;
    cout << avoidRoads.numWays(2, 100, std::vector<string>()) << endl;
    return 0;
    for (i = 0; i < T; ++i) {
        int width, height;

        getline(cin, s);
        ss.str(s);
        ss.clear();
        ss >> width;

        getline(cin, s);
        ss.str(s);
        ss.clear();
        ss >> height;

        getline(cin, s);
        stringstream string_ss(s);
        string item;
        std::vector<string> bad;
        while (getline(string_ss, item, ':')) {
            bad.push_back(item);
        }

        cout << "Test Case [" << i << "]" << endl;
        cout << "--------------------------------------------------" << endl;
        #ifdef DEBUG
        cout << " * width: " << width << ", height: " << height << endl;
        cout << " * bad roads: ";
        for (auto i : bad) {
            cout << "{" <<i << "} ";
        }
        cout << endl;
        #endif

        getline(cin, s);
        ss.str(s);
        ss.clear();
        int64_t ans;
        ss >> ans;

        AvoidRoads avoidRoads;
        int64_t user_ans = avoidRoads.numWays(width, height, bad);

        #ifdef DEBUG
        cout << " * ans: " << ans << endl;
        cout << " * user ans: " << user_ans << endl;
        #endif
        
        cout << ((ans==user_ans) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }

    return 0;
}

