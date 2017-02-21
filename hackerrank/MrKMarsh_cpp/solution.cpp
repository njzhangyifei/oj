#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m, n;
    cin >> m >> n;

    uint8_t map[m][n];
    int i,j, k;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            char ch;
            cin >> ch;
            if (ch == 'x') {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }

    int map_up[m][n];
    int map_left[m][n];

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            // for each [m, n]
            // go right
            if (map[i][j]) {
                map_left[i][j] = -1;
                continue;
            }
            int distance = 0;
            for (k = j-1; k >= 0; --k) {
                if (map[i][k]) {
                    break;
                }
                distance ++;
            }
            map_left[i][j] = distance;
        }
    }

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            // for each [m, n]
            // go right
            if (map[i][j]) {
                map_up[i][j] = -1;
                continue;
            }
            int distance = 0;
            for (k = i-1; k >= 0; --k) {
                if (map[k][j]) {
                    break;
                }
                distance ++;
            }
            map_up[i][j] = distance;
        }
    }

#ifdef DEBUG
    cout << "m=" << m << ", n=" << n << endl;
    cout << "Left Map" << endl;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            cout << map_left[i][j] << "\t";
            // cout << (map[i][j] ? 1 : 0) << " ";
        }
        cout << endl;
    }

    cout << "Up Map" << endl;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            cout << map_up[i][j] << "\t";
        }
        cout << endl;
    }
#endif

    int max_perimeter = 0;
    int top, bottom;
    for (top = 0; top < m-1; ++top) {
        for (bottom = top+1; bottom < m; ++bottom) {
            std::vector<int> rows;
            int top_bottom_diff = bottom - top;
            // cout << "topbottom diff " << top_bottom_diff << endl;
            for (i = 0; i < n; ++i) {
                if (map_up[bottom][i] >= top_bottom_diff) {
                    rows.push_back(i);
                    // cout << "- pushing " << i << endl;
                }
            }
            // we had all the possible rows
            // we need to find the left side and right side among these rows
            int left, right;
            left = 0;
            for (right = 0; right < rows.size(); ++right) {
                // go thru all the rows
                int min_left = rows[right] - 
                    min(map_left[bottom][rows[right]], 
                            map_left[top][rows[right]]);
                // cout << " min left =" << min_left << endl;
                while (rows[left] < min_left) {
                    left++;
                }
                if (rows[right] > rows[left]) {
                    int perimeter = 
                        2 * (top_bottom_diff + (rows[right] - rows[left]));
                    // cout << " h=" << top_bottom_diff << " w=" 
                        // <<(rows[right] - rows[left]);
                    // cout << " peri=" << perimeter << endl;
                    if (perimeter > max_perimeter) {
                        max_perimeter = perimeter;
                    }
                }
            }
        }
    }

    if (max_perimeter) {
        cout << max_perimeter << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}
