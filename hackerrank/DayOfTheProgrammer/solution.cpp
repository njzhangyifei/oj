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
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

std::vector<int> calendar = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 3000};
std::vector<int> sp = {0, 14+32, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 3000};

int feb_index = 1;
int change=1919;
int pg_day = 256;

bool leap_j (int year) {
    return (year % 4 == 0);
}

bool leap_g (int year) {
    return (year % 400 == 0) || ( (year % 4 == 0) && (year % 100 != 0));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int year;
    // year = 2016;
    cin >> year;

    int month = 0;
    int day = 0;
    if (year < 1918) {
        // j
        auto cal = calendar;
        if (leap_j(year)) {
            cal[feb_index] = 29;
        }
        int temp = pg_day;
        for (int i = 0; i < 12; ++i) {
            temp -= cal[i];
            if (temp < 0) {
                month = i + 1;
                day = temp + cal[i];
                break;
            }
        }
    } else if (year == 1918) {
        auto cal = sp;
        int temp = pg_day;
        for (int i = 0; i < 12; ++i) {
            temp -= cal[i];
            if (temp < 0) {
                month = i + 1;
                day = temp + cal[i];
                break;
            }
        }
    } else {
        // g
        auto cal = calendar;
        if (leap_g(year)) {
            cal[feb_index] = 29;
        }
        int temp = pg_day;
        for (int i = 0; i < 12; ++i) {
            temp -= cal[i];
            if (temp < 0) {
                month = i + 1;
                day = temp + cal[i];
                break;
            }
        }
    }

    fprintf(stdout, "%02d.%02d.%d\n", day, month, year);

    return 0;
}

