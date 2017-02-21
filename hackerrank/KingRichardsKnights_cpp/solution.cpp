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

// #define DEBUG

pair<int, int> operator + (const pair<int, int> &lhs, const pair<int, int> &rhs){
    return pair<int, int>(lhs.first+rhs.first, lhs.second+rhs.second);
}

struct command{
    
    pair<int, int> translation;
    pair<int, int> original_top_left;
    pair<int, int> original_top_right;
    pair<int, int> original_bottom_left;
    pair<int, int> original_bottom_right;
    pair<int, int> world_top_left;
    pair<int, int> world_top_right;
    pair<int, int> world_bottom_left;
    pair<int, int> world_bottom_right;
    int length;

    int rotation_count;

    command(command * prev_command, int tl_x, int tl_y, int length){
        this->original_top_left.first = tl_x;
        this->original_top_left.second = tl_y;
        this->original_bottom_left.first = tl_x + length;
        this->original_bottom_left.second = tl_y;
        this->original_top_right.first = tl_x;
        this->original_top_right.second = tl_y + length;
        this->original_bottom_right.first = tl_x + length;
        this->original_bottom_right.second = tl_y + length;
        this->length = length;
        if (prev_command == NULL) {
            this->rotation_count = 1;
            this->world_top_left = original_top_left;
            this->world_top_right = original_top_right;
            this->world_bottom_left = original_bottom_left;
            this->world_bottom_right = original_bottom_right;
            this->translation.first = 0;
            this->translation.second = 0;
        } else {
            this->rotation_count = (prev_command->rotation_count + 1) % 4;
            auto reverted_pair = 
                prev_command->revert_command_world(this->original_top_left);
            switch (rotation_count) {
                case 1:
                    // tl
                    this->world_bottom_left =
                        reverted_pair + pair<int,int>(length, 0);
                    break;
                case 2:
                    // this is bottom left
                    this->world_bottom_left = reverted_pair;
                    break;
                case 3:
                    // br
                    this->world_bottom_left =
                        reverted_pair + pair<int,int>(0, -length);
                    break;
                case 0:
                    // tr
                    this->world_bottom_left =
                        reverted_pair + pair<int,int>(length, -length);
                    break;
                default:
                    break;
            }
            this->world_top_left = 
                this->world_bottom_left + pair<int, int>(-length, 0);
            this->world_top_right = 
                this->world_top_left + pair<int, int>(0, length);
            this->world_bottom_right = 
                this->world_top_left + pair<int, int>(length, length);

            #ifdef DEBUG
            cerr << "to be reverted = " 
                << this->original_top_left.first << ", " << this->original_top_left.second << endl;
            cerr << "reverted = "
                << this->world_bottom_left.first << ", " << this->world_bottom_left.second << endl;
            cerr << "top_left = "
                << this->world_top_left.first << ", " << this->world_top_left.second << endl;
            #endif

            this->translation.first = 
                original_top_left.first - world_top_left.first;
            this->translation.second = 
                original_top_left.second - world_top_left.second;
        }
    }

    bool contains_world(pair<int, int> point){
        if (point.second <= world_top_right.second && point.second >= world_top_left.second) {
            if (point.first <= world_bottom_left.first && point.first >= world_top_left.first) {
                return true;
            }
        }
        return false;
    }

    pair<int, int> apply_command_world(pair<int, int> orig){
        int i;
        if (length != 0) {
            for (i = 0; i < rotation_count; ++i) {
                int original_x = orig.first;
                int original_y = orig.second;
                int delta_x = original_x - world_top_left.first;
                int delta_y = original_y - world_top_left.second;
                int new_x = delta_y + world_top_left.first;
                int new_y = (length - delta_x) + world_top_left.second;
                orig.first = new_x;
                orig.second = new_y;
            }
        }
        return pair<int, int>(
                orig.first + translation.first, 
                orig.second + translation.second
                );
    }

    pair<int, int> revert_command_world(pair<int, int> orig){
        #ifdef DEBUG
        if (length == 1) {
            cerr << "orig : " << orig.first << ", " << orig.second << endl;
        }
        #endif
        orig.first -= translation.first;
        orig.second -= translation.second;
        int i;
        for (i = 0; i < rotation_count; ++i) {
            int original_x = orig.first;
            int original_y = orig.second;
            int delta_x = original_x - world_top_left.first;
            int delta_y = original_y - world_top_left.second;
            int new_x = length - delta_y + world_top_left.first;
            int new_y = delta_x + world_top_left.second;
            orig.first = new_x;
            orig.second = new_y;
        }
        return pair<int, int>(orig.first, orig.second);
    }
};

int binary_search(vector<command *> * v_command, pair<int, int> knight) {
    int lo = 0;
    int hi = v_command->size();
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        ans = mid;
        if (mid == v_command->size()) {
            break;
        }
        auto current_command = v_command->operator[](mid);
        if (!current_command->contains_world(knight)) {
            if (mid == 0) {
                break;
            }
            if (v_command->operator[](mid-1)->contains_world(knight)) {
                break;
            }
        }
        if (!current_command->contains_world(knight)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

pair<int, int> get_knight(int64_t no, int64_t N){
    int x = no / N;
    int y = no % N;
    return pair<int, int>(x, y);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i;

    int N;
    cin >> N;

    int S;
    cin >> S;
    std::vector<command *> * v_command = new vector<command *>(S);
    for (i = 0; i < S; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        a --; b--;
        command * new_command;
        if (i > 0) {
            new_command = new command(v_command->operator[](i-1), a, b, d);
        } else {
            new_command = new command(NULL, a, b, d);
        }
        v_command->operator[](i) = new_command;
    }

    #ifdef DEBUG
    cerr << "-- v_command -----------" << endl;
    for (auto i : (*v_command)) {
        cerr << "length : " << i->length << endl;
        cerr << "rotation_count : " << i->rotation_count << endl;
        cerr << "world_top_left : ";
        cerr << i->world_top_left.first << ", " 
            << i->world_top_left.second << endl;
        cerr << "translation : " << i->translation.first << ", " << i->translation.second << endl;
        cerr << endl;
    }
    #endif

    int L;
    cin >> L;
    for (i = 0; i < L; ++i) {
        int64_t knight;
        cin >> knight;
        auto k = get_knight(knight, N);
        int res = binary_search(v_command, k);
        #ifdef DEBUG
        cerr << "binary_search result = " << res << endl;
        #endif
        pair<int, int> ans = k;
        if (res != 0) {
            res -= 1;
            ans = v_command->operator[](res)->apply_command_world(k);
        }
        ans.first ++; ans.second++;
        // printf("%d %d\n",  k.first, k.second);
        // cout << "\r" << i << "/" << L << " - ";
        cout << ans.first << " " << ans.second;
        cout << endl;
    }



    return 0;
}

