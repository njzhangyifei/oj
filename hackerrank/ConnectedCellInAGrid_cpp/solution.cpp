#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int floodfill(
        uint8_t ** map, int M, int N,
        int x, int y,
        uint8_t wall, uint8_t color
        )
{
    if (x < 0 || x >= M) {
        return 0;
    }
    if (y < 0 || y >= N) {
        return 0;
    }

    int count = 0;
    uint8_t current = map[x][y];

    if (current == color) {
        // visited
        return 0;
    }
    if (current == wall) {
        return 0;
    }
    map[x][y] = color;
    count = 1;

    count += floodfill(map, M, N, x-1, y-1, wall, color);
    count += floodfill(map, M, N, x-1, y, wall, color);
    count += floodfill(map, M, N, x-1, y+1, wall, color);
    count += floodfill(map, M, N, x, y-1, wall, color);
    count += floodfill(map, M, N, x, y, wall, color);
    count += floodfill(map, M, N, x, y+1, wall, color);
    count += floodfill(map, M, N, x+1, y-1, wall, color);
    count += floodfill(map, M, N, x+1, y, wall, color);
    count += floodfill(map, M, N, x+1, y+1, wall, color);

    return count;
}

int solve(uint8_t ** map, int M, int N)
{
    int max_flood_fill = 0;
    int color = 1;
    int i, j;
    for (i = 0; i < M; ++i) {
        for (j = 0; j < N; ++j) {
            max_flood_fill = max(floodfill(map, M, N, i, j, 0, color++), max_flood_fill);
        }
    }
    return max_flood_fill;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M;
    cin >> M >> N;

    int i, j;
    uint8_t ** map = new uint8_t * [M];
    for (i = 0; i < M; ++i) {
        map[i] = new uint8_t[N];
        memset(map[i], 0, sizeof(uint8_t) * N);
    }

    for (i = 0; i < M; ++i) {
        for (j = 0; j < N; ++j) {
            int input = 0;
            cin >> input;
            if (input == 1) {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }

    int ans = solve(map, M, N);
    cout << ans << endl;

    return 0;
}

