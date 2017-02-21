#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define left(x)   (2*x + 1)
#define right(x)  (2*x + 2)
#define parent(x) ((x-1)/2)
int heapsize;
vector<long> minheap;


long min(){
    return minheap[0];
}

void insert(long val){
    minheap.push_back(val);
    int index = heapsize;
    while ( index != 0 && minheap[parent(index)] > minheap[index]){
        long temp = minheap[parent(index)];
        minheap[parent(index)] =minheap[index];
        minheap[index] = temp;
        int newIndex = parent(index);
        if (newIndex == 0 && minheap[newIndex] > minheap[index]) {
            long temp = minheap[newIndex];
            minheap[newIndex] =minheap[index];
            minheap[index] = temp;
            break;
        } else {
            index=newIndex;
        }
    }
    heapsize ++;
}

void remove(long val) {
    long lastElement = minheap[--heapsize];
    if (lastElement == val) {
        return;
    }
    
    int index = 0;
    for (int i = 0; i < heapsize; i++) {
        if (minheap[i] == val) {
            // found, delete
            minheap[i] = lastElement;
            index = i;
            break;
        }
    }
    
    if (minheap[parent(index)] > minheap[index]) {
        // go up
        while ( index != 0 && minheap[parent(index)] > minheap[index]){
            long temp = minheap[parent(index)];
            minheap[parent(index)] =minheap[index];
            minheap[index] = temp;
            int newIndex = parent(index);
            if (newIndex == 0 && minheap[newIndex] > minheap[index]) {
                long temp = minheap[newIndex];
                minheap[newIndex] =minheap[index];
                minheap[index] = temp;
                break;
            } else {
                index=newIndex;
            }
        }
    } else {
        if ((left(index) < heapsize && (minheap[left(index)]) < minheap[index]) || 
            (right(index) < heapsize && (minheap[right(index)]) < minheap[index] )) {
            // sift down
            while ( (left(index) < heapsize) && (right(index) < heapsize)){
                long leftval = minheap[left(index)];
                long rightval = minheap[right(index)];
                int indexToSwap = 0;

                if (leftval < rightval) {
                    indexToSwap = left(index);
                }  else {
                    indexToSwap = right(index);
                }
               
                if (minheap[index] < minheap[indexToSwap]) {
                    break;
                }

                long temp = minheap[indexToSwap];
                minheap[indexToSwap] = minheap[index];
                minheap[index] = temp;
                index = indexToSwap;

            }
        }
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    for (int i  = 0; i< N; i++) {
        int op;
        long param;
        cin >> op;
        if (op != 3) {
            cin >> param;
        }
        if (op == 1) {
            insert(param);
        }
        if (op == 2) {
            remove(param);
        }
        if (op == 3) {
            cout << min() << endl;
        }
    }
    return 0;
}

