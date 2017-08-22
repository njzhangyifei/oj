#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iterator>
#include <numeric>
#include <memory>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> * data;
    stack<int> * mins;
    int minimum = INT_MAX;
    MinStack() {
        data = new stack<int>();
        mins = new stack<int>();
    }
    
    void push(int x) {
        if (x < minimum) {
            minimum = x;
        }
        data->push(x);
        mins->push(minimum);
    }
    
    void pop() {
        data->pop();
        mins->pop();
        if (mins->size()) {
            minimum = mins->top();
        } else {
            minimum = INT_MAX;
        }
    }
    
    int top() {
        return data->top();
    }
    
    int getMin() {
        return mins->top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

