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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N;
    cin >> N;
    std::queue<int64_t> q_student;

    int64_t i;
    for (i = 0; i < N; ++i) {
        int t;
        cin >> t;
        q_student.push(t);
    }

    int best_index = 0;
    int best_count = 0;
    for (i = 0; i < q_student.size(); ++i) {
        std::queue<int64_t> q_temp = q_student;
        int64_t j;
        for (j = 0; j < i; ++j) {
            int64_t temp = q_temp.front();
            // temp -= (N - i + j);
            q_temp.pop();
            q_temp.push(temp);
        }
        int count = 0;
        for (j = 0; j < N; ++j) {
            if (q_temp.front() <= j) {
                count ++;
            }
            // cout << q_temp.front() << " ";
            q_temp.pop();
        }
        cout << "i = " << i << " count = " << count << endl;
        if (best_count < count) {
            best_count = count;
            best_index = i;
        }
    }

    cout << best_index+1 << endl;
    return 0;
}

