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

struct rotation {
    pair<int, int> top_left;
    pair<int, int> top_right;
    pair<int, int> bottom_left;
    pair<int, int> bottom_right;
    int length;

    rotation(int tl_x, int tl_y, int length){
        this->top_left.first = tl_x;
        this->top_left.second = tl_y;
        this->bottom_left.first = tl_x + length;
        this->bottom_left.second = tl_y;
        this->top_right.first = tl_x;
        this->top_right.second = tl_y + length;
        this->bottom_right.first = tl_x + length;
        this->bottom_right.second = tl_y + length;
        this->length = length;
    }

    bool contains(pair<int, int> point){
        if (point.second <= top_right.second && point.second >= top_left.second) {
            if (point.first <= bottom_left.first && point.first >= top_left.first) {
                return true;
            }
        }
        return false;
    }

    pair<int, int> apply_rotation(pair<int, int> orig){
        int original_x = orig.first;
        int original_y = orig.second;
        int delta_x = original_x - top_left.first;
        int delta_y = original_y - top_left.second;
        int new_x = delta_y + top_left.first;
        int new_y = (length - delta_x) + top_left.second;
        return pair<int, int>(new_x, new_y);
    }


};

pair<int, int> get_knight(int64_t no, int N){
    int x = no / N;
    int y = no % N;
    return pair<int, int>(x, y);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    // int i;
    // for (i = 0; i < 10; ++i) {
        // auto p =  get_knight(i, 7);
        // cerr << p.first << ", " << p.second << endl;
    // }
    // rotation t(0, 1, 4);
    // cerr << t.contains(pair<int, int>(0, 0));

    // auto res = t.apply_rotation(pair<int, int>(0, 5));
    // cerr << res.first << ", " << res.second << endl;

    int i, j;

    int N;
    scanf("%d", &N);


    int S;
    scanf("%d", &S);

    std::vector<rotation *> * v_rotation = new std::vector<rotation *>(S);
    for (i = 0; i < S; ++i) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        a--; b--;
        v_rotation->operator[](i) = new rotation(a,b,d);
    }

    int L;
    cin >> L;
    for (i = 0; i < L; ++i) {
        int64_t knight;
        cin >> knight;
        auto k = get_knight(knight, N);
        for (j = 0; j < S; ++j) {
            auto ptr_rotation = v_rotation->operator[](j);
            if (ptr_rotation->contains(k)) {
                // contains
                k = ptr_rotation->apply_rotation(k);
            } else {
                break;
            }
        }
        k.first++; k.second++;
        printf("\r %d / %d - %d %d", i, L, k.first, k.second);
        // printf("%d %d\n",  k.first, k.second);
        // cout << "\r" << i << "/" << L << " - ";
        // cout << k.first << " " << k.second;
    }

    return 0;
}
