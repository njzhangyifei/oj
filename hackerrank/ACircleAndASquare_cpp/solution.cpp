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

using namespace std;

uint8_t raster[101][101];

bool distanceCompare(double x1, double y1, double x2, double y2, double dist){
    double distt = (x1-x2) * (x1-x2) + (y1 - y2) * (y1 - y2);
    return (distt <= (dist * dist));
}

void draw_circle(int r, int x, int y) {
    int i, j;
    for (i = x-r; i <= x + r; ++i) {
        for (j = y-r; j <= y + r; ++j) {
            if (distanceCompare(0.5+i, 0.5+j, 0.5+x, 0.5+y, r)) {
                // draw
                if ((i >= 0 || i <= 100) && (j >= 0 || j <= 100)){
                    raster[i][j] = '#';
                }
            }
        }
    }
}

void draw_square(double x1, double y1, double x3, double y3){
    double centerx = ((double)(x3+x1)) / 2.0;
    double centery = ((double)(y3+y1)) / 2.0;

    double centerxh = ((double)(x3-x1)) / 2.0;
    double centeryh = ((double)(y3-y1)) / 2.0;

    double x2 = centerx - centeryh;
    double y2 = centery + centerxh;
    double x4 = centerx + centeryh;
    double y4 = centery - centerxh;

    int xx1 = (int)(x1 -0.5);
    int yy1 = (int)(y1 -0.5);
    int xx2 = (int)(x2 -0.5);
    int yy2 = (int)(y2 -0.5);
    int xx3 = (int)(x3 -0.5);
    int yy3 = (int)(y3 -0.5);
    int xx4 = (int)(x4 -0.5);
    int yy4 = (int)(y4 -0.5);

    double slope2_1 = (y2 - y1) / (x2 - x1);
    double slope4_1 = (y4 - y1) / (x4 - x1);

    double slope2_3 = (y2 - y3) / (x2 - x3);
    double slope4_3 = (y4 - y3) / (x4 - x3);

    int i, j;
    for (i = 0; i < 101; ++i) {
        for (j = 0; j < 101; ++j) {
            double xx = i + 0.5;
            double yy = j + 0.5;
            if (slope2_1 * (xx - x1) + y1 <= yy) {
                raster[i][j] = '-';
            }
        }
    }

    for (i = 0; i < 101; ++i) {
        for (j = 0; j < 101; ++j) {
            double xx = i + 0.5;
            double yy = j + 0.5;
            if (slope4_1 * (xx - x1) + y1 >= yy) {
                if (raster[i][j] == '-') {
                    raster[i][j] = '=';
                }
            }
        }
    }

    for (i = 0; i < 101; ++i) {
        for (j = 0; j < 101; ++j) {
            double xx = i + 0.5;
            double yy = j + 0.5;
            if (slope2_3 * (xx - x3) + y3 <= yy) {
                if (raster[i][j] == '=') {
                    raster[i][j] = '+';
                }
            }
        }
    }

    for (i = 0; i < 101; ++i) {
        for (j = 0; j < 101; ++j) {
            double xx = i + 0.5;
            double yy = j + 0.5;
            if (slope4_3 * (xx - x3) + y3 >= yy) {
                if (raster[i][j] == '+') {
                    raster[i][j] = '#';
                }
            }
        }
    }
    for (i = 0; i < 101; ++i) {
        for (j = 0; j < 101; ++j) {
            if (raster[i][j] != '#') {
                raster[i][j] = '.';
            }
        }
    }

    raster[xx1][yy1] = '!';
    raster[xx2][yy2] = '*';
    raster[xx3][yy3] = '!';
    raster[xx4][yy4] = '*';


}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int w;
    int h;
    cin >> w >> h;
    int circleX;
    int circleY;
    int r;
    cin >> circleX >> circleY >> r;
    int x1;
    int y1;
    int x3;
    int y3;
    cin >> x1 >> y1 >> x3 >> y3;
    // your code goes here
    
    draw_square(0.5+x1, 0.5+y1, 0.5+x3, 0.5+y3);
    draw_circle(r, circleX, circleY);

    int i, j;
    for (i = 0; i < h; ++i) {
        for (j = 0; j < w; ++j) {
            cout << (raster[j][i] ? (char)raster[j][i] : '.'); 
        }
        cout << endl;
    }
    return 0;
}

