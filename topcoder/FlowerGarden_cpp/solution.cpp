#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

// #define DEBUG

class FlowerGarden
{
public:
    bool checkBlocking(
            int height_1, int bloom_1, int wilt_1,
            int height_2, int bloom_2, int wilt_2){
        // cout << "height " << height_1 << " " << height_2 << endl;
        // cout << "bloom " << bloom_1 << " " << bloom_2 << endl;
        // cout << "wilt " << wilt_1 << " " << wilt_2 << endl;
        if (height_1 < height_2) {
            return false;
        }
        // 1 is in front of 2
        // height 1 < height 2, -> will not block
        // height 1 > height 2 -> will block sometimes
        //
        // 1 first bloom
        //  ----------
        //         ----------  1 wilt > 2 bloom
        //
        //  -----------        1 wilt > 2 bloom
        //     ------          2 wilt > 1 bloom       
        //
        //  ---------
        //            -------
        //
        // 2 first bloom
        //                ---------------
        //            ------    2 wilt > 1 bloom
        //                      ---------------
        //            ------
        if ((wilt_1 >= bloom_2 && bloom_1 <= wilt_2)) {
            return true;
        }
        return false;
    }

    struct flower {
        int height;
        int bloom;
        int wilt;
    };

    struct by_height {
        bool operator()(flower const & a, flower const & b) {
            return a.height > b.height;
        }
    };

    vector<int> getOrdering(
            vector<int> height, vector<int> bloom, vector<int> wilt) {
        std::vector<int> order;
        int num_types = height.size();
        uint8_t block_map [num_types][num_types];
        int i, j;

        std::vector<flower> flowers(num_types);
        for (i = 0; i < num_types; ++i) {
            flowers[i].height = height[i];
            flowers[i].bloom = bloom[i];
            flowers[i].wilt = wilt[i];
        }
        sort(flowers.begin(), flowers.end(), by_height());

#ifdef DEBUG
        cout << "sorted flowers:" << endl;
        for (i = 0; i < num_types; ++i) {
            cout << flowers[i].height;
        }
#endif

        for (i = 0; i < num_types; ++i) {
            for (j = 0; j < num_types; ++j) {
                // check for blocking
                flower & f_i = flowers[i];
                flower & f_j = flowers[j];
                block_map[i][j] = (
                    (checkBlocking(f_i.height, f_i.bloom, f_i.wilt,
                        f_j.height, f_j.bloom, f_j.wilt)) ? 1 : 0);
                block_map[j][i] = (
                    (checkBlocking(f_j.height, f_j.bloom, f_j.wilt,
                        f_i.height, f_i.bloom, f_i.wilt)) ? 1 : 0);
            }
        }

        for (i = num_types-1; i >= 0; --i) {
            for (j = 0; j < order.size(); ++j) {
                int existing_type = order[j];
                if (block_map[i][existing_type]) {
#ifdef DEBUG
                    cout << flowers[i].height << " will block " << flowers[existing_type].height << endl;
#endif
                    break;
                }
            }

#ifdef DEBUG
            cout << "order:" << endl;
            for (auto i : order) {
                cout << flowers[i].height << " ";
            }
            cout << endl;

            cout << "insert " << flowers[i].height << endl;
            cout << endl;
#endif
            // insert into place
            order.insert(order.begin() + j, i);
        }

#ifdef DEBUG
        cout << "block_map:" << endl;
        for (i = 0; i < num_types; ++i) {
            for (j = 0; j < num_types; ++j) {
                cout << (int)block_map[i][j] << " ";
            }
            cout << endl;
        }

        cout << "order:" << endl;
        for (auto i : order) {
            cout << flowers[i].height << " ";
        }
#endif

        reverse(order.begin(), order.end());

        std::vector<int> res(num_types);
        for (i = 0; i < num_types; ++i) {
            res[i] = flowers[order[i]].height;
        }


        return res;
    }

private:
    /* data */
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    stringstream ss;
    getline(cin, s);
    ss.str(s);

    int T;
    ss >> T;
    
    int i;
    for (i = 0; i < T; ++i) {
        int x;
        std::vector<int> height;
        std::vector<int> bloom;
        std::vector<int> wilt;

        getline(cin, s);
        ss.str(s);
        ss.clear();
        while (ss >> x) {
            height.push_back(x);
        }

        getline(cin, s);
        ss.str(s);
        ss.clear();
        while (ss >> x) {
            bloom.push_back(x);
        }

        getline(cin, s);
        ss.str(s);
        ss.clear();
        while (ss >> x) {
            wilt.push_back(x);
        }

        getline(cin, s);
        ss.str(s);
        ss.clear();
        std::vector<int> ans;
        while (ss >> x) {
            ans.push_back(x);
        }

        cout << "-----------------------------------------------" << endl;
        cout << " * height: ";
        for (auto i : height) {
            cout << i << " ";   
        }
        cout << endl;
        cout << " * bloom: ";
        for (auto i : bloom) {
            cout << i << " ";   
        }
        cout << endl;
        cout << " * wilt: ";
        for (auto i : wilt) {
            cout << i << " ";   
        }
        cout << endl;

        FlowerGarden f;
        std::vector<int> user_ans = f.getOrdering(height, bloom, wilt);

        cout << " * ans: ";
        for (auto i : ans) {
            cout << i << " ";   
        }
        cout << endl;
        cout << " * user_ans: ";
        for (auto i : user_ans) {
            cout << i << " ";   
        }
        cout << endl;
        cout << ((ans==user_ans) ? "PASSED" : "FAILED") << endl;
    }
    return 0;
}

