#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solve(int price[], int N){
    int max_price = price[N-1];
    uint8_t options[N]; // 0 -> sell, 1 -> buy
    options[N-1] = 0;
    long long profit = 0;
    int i;
    for (i = N-1; i >= 0 ; --i) {
        int current_price = price[i];
        if (current_price > max_price) {
            options[i] = 0;
            max_price = current_price;
        } else if (current_price < max_price){
            // buy
            profit += (max_price - current_price);
            options[i] = 1;
        }
    }
    return profit;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;

    int i;
    for (i = 0; i < T; ++i) {
        int N;
        cin >> N;
        int price[N];
        int j;
        for (j = 0; j < N; ++j) {
            cin >> price[j];   
        }
        long long profit = solve(price, N);
        cout << profit << endl;
    }


    return 0;
}

