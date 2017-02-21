#define __USE_MINGW_ANSI_STDIO 1

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

// #define DEBUG

int abs_int64(int t){
    if (t < 0) {
        return (-t);
    } else {
        return t;
    }
}

using namespace std;

int binary_search(vector<int64_t> * sorted, int64_t val){
    int size = sorted->size();
    int lo = 0;
    int hi = size;
    int ans_index = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / (int)(2);
        int current_element = sorted->operator[](mid);
        ans_index = mid;
        if (current_element >= val) {
            if (mid == 0) {
                break;
            }
            if (sorted->operator[](mid - 1) < val) {
                break;
            }
        }
        if (current_element >= val) {
            // go left
            hi = mid-1;
        } else {
            // go right
            lo = mid+1;
        }
    }
    return ans_index;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print64_t output to STDOUT */   

    int64_t N;
    int64_t Q;
    int64_t i;
    std::vector<int64_t> * input = new std::vector<int64_t>();
    std::vector<int64_t> * prefix_sum = new std::vector<int64_t>();
    std::vector<int64_t> * prefix_abs_sum = new std::vector<int64_t>();
    cin >> N;

    for (i = 0; i < N; ++i) {
        int64_t in;
        cin >> in;
        input->push_back(in);
    }

    sort(input->begin(), input->end());

    prefix_sum->push_back(0);
    prefix_abs_sum->push_back(0);

    int64_t abs_sum = 0;
    int64_t sum = 0;
    for (i = 0; i < input->size(); ++i) {
        sum += input->operator[](i);
        abs_sum += abs_int64(input->operator[](i));
        prefix_sum->push_back(sum);
        prefix_abs_sum->push_back(abs_sum);
    }

    int64_t pos_zero = binary_search(input, 0);

    #ifdef DEBUG
    for (auto i : (*input)) {
        cerr << i << ", ";
    }
    cerr << endl;
    cerr << "pos_zero = " << pos_zero << endl;
    #endif


    cin >> Q;

    int64_t q = 0;
    for (i = 0; i < Q; ++i) {
        // conduct query
        int64_t in = 0;
        cin >> in;

        q = q + in;

        int pos_neg_q = binary_search(input, -q);

        #ifdef DEBUG
        cerr << "q = " << q;
        cerr << " pos_neg_q: " << pos_neg_q << " pos_zero: " << pos_zero << endl;
        #endif

        int64_t result = 0;
        if ((-q) <= 0) {
            // -q is on the left
            // -q    0    q
            int64_t left = (*prefix_abs_sum)[pos_neg_q] + (pos_neg_q * (-q));
            int64_t right = (*prefix_abs_sum)[input->size()] - (*prefix_abs_sum)[pos_zero];
            right += (input->size() - pos_zero) * q;

            int64_t middle = (*prefix_sum)[pos_zero] - (*prefix_sum)[pos_neg_q];
            middle = -abs_int64(middle);
            middle += (pos_zero - pos_neg_q) * q;

            result = left + right + middle;

            #ifdef DEBUG
            cerr << "left = " << left 
                << " right = " << right 
                << " middle = " << middle
                << endl;
            #endif
        } else {
            // -q is on the right
            // q    0    -q
            int64_t left = (*prefix_abs_sum)[pos_zero] + (pos_zero * (-q));
            int64_t right = (*prefix_abs_sum)[input->size()] - (*prefix_abs_sum)[pos_neg_q];
            right += (input->size() - pos_neg_q) * q;

            int64_t middle = (*prefix_sum)[pos_neg_q] - (*prefix_sum)[pos_zero];
            middle = -abs_int64(middle);
            middle += (pos_neg_q - pos_zero) * (-q);

            result = left + right + middle;

            #ifdef DEBUG
            cerr << "left = " << left 
                << " right = " << right 
                << " middle = " << middle
                << endl;
            #endif
            
        }
        // printf("%lld\r\n", result);
        cout << result << endl;
    }

    return 0;
}

