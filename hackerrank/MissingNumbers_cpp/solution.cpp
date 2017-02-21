#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>
#include <map>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

std::vector<int> l1;
std::vector<int> l2;
map<int, int> freq_l1;
map<int, int> freq_l2;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int len_l1;
    int len_l2;

    int i;
    int num;

    cin >> len_l1;
    for (i = 0; i < len_l1; ++i) {
        cin >> num;
        freq_l1[num]++;
        l1.push_back(num);
    }

    cin >> len_l2;
    for (i = 0; i < len_l2; ++i) {
        cin >> num;
        freq_l2[num]++;
        l2.push_back(num);
    }

    std::vector<int> missing_num;
    std::map<int, bool> missing_num_map;
    if (len_l1 < len_l2) {
        for (i = 0; i < len_l2; ++i) {
            num = l2[i];
            if (freq_l2[num] != freq_l1[num]) {
                if (!missing_num_map[num]) {
                    missing_num.push_back(num);
                    missing_num_map[num] = true;
                }
            }
        }
    } else {
        for (i = 0; i < len_l1; ++i) {
            num = l1[i];
            if (freq_l2[num] != freq_l1[num]) {
                if (!missing_num_map[num]) {
                    missing_num.push_back(num);
                    missing_num_map[num] = true;
                }
            }
        }
    }

    sort(missing_num.begin(), missing_num.end());

    for (auto i : missing_num) {
        cout << i << " ";
    }

    return 0;
}

