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

class MedianFinder {
    public:
        /** initialize your data structure here. */
        std::multiset<int> * lower;
        std::multiset<int> * upper;
        int count;
        double median;
        MedianFinder() {
            count = 0;
            median = 0;
            lower = new std::multiset<int>();
            upper = new std::multiset<int>();
        }

        void addNum(int num) {
            count ++;
            if (count == 1) {
                median = num;
                lower->insert(num);
                return;
            }
            bool odd = count % 2;
            if (num <= median) {
                lower->insert(num);
                if (odd) {
                    // even => odd
                    median = *prev(lower->end());
                } else {
                    int lst = *prev(lower->end());
                    lower->erase(prev(lower->end()));
                    upper->insert(lst);
                    median = *prev(lower->end()) + *upper->begin();
                    median /= 2.0;
                }
            } else {
                upper->insert(num);
                if (odd) {
                    // even => odd
                    median = *(upper->begin());
                } else {
                    median = *prev(lower->end()) + *upper->begin();
                    median /= 2.0;
                    cerr << "size=" << upper->size() << endl;
                    int fst = *(upper->begin());
                    upper->erase(upper->begin());
                    lower->insert(fst);
                }
            }
        }

        double findMedian() {
            cerr << "lower: ";
            for (auto i : *lower) {
                cerr << i << " ";
            }
            cerr << endl;

            cerr << "upper: ";
            for (auto i : *upper) {
                cerr << i << " ";
            }
            cerr << endl;
            return median;
        }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    MedianFinder s;
    std::vector<int> v = 
    // {12, 10, 13, 11, 5, 15, 1, 11, 6, 17, 14,8,17,6,4,16,8,10,2,12,0};
    // {1, 2, 3};
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto i : v) {
        s.addNum(i);
        cerr << s.findMedian() << endl;
    }
    return 0;
}

