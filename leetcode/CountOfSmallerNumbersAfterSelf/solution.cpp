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

class Solution {
public:

    void merge(
            vector<int> & nums, 
            vector<int> & index, 
            vector<int> & count,
            int start, int end) {
        std::vector<int> next_index(end-start+1, 0);
        int curr = 0;
        int mid = (start + end) / 2;
        int inversion_count = 0;
        int l1_idx = start;
        int l2_idx = mid + 1;
        while (l1_idx <= mid && l2_idx <= end) {
            if (nums[index[l1_idx]] <= nums[index[l2_idx]]) {
                // correct
                next_index[curr] = index[l1_idx];
                count[next_index[curr]] += (inversion_count);
                l1_idx++;
            } else {
                // inversion
                next_index[curr] = index[l2_idx];
                inversion_count ++;
                l2_idx++;
            }
            curr ++;
        }
        for (int i = l1_idx; i <= mid; ++i) {
            next_index[curr ] = index[i];
            count[next_index[curr]] += (inversion_count);
            curr++;
        }
        for (int i = l2_idx; i <= end; ++i) {
            next_index[curr ++ ] = index[i];
        }

        for (int i = start; i <= end; ++i) {
            index[i] = next_index[i-start];
        }
    }

    void mergeSort(
            vector<int> & nums, 
            vector<int> & index, 
            vector<int> & count,
            int start, int end){
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        mergeSort(nums, index, count, start, mid);
        mergeSort(nums, index, count, mid+1, end);
        merge(nums, index, count, start, end);
    }

    vector<int> countSmaller(vector<int>& nums) {
        std::vector<int> v;
        for (int i = 0; i < nums.size(); ++i) {
            v.push_back(i);
        }
        std::vector<int> res (nums.size(), 0);
        mergeSort(nums, v, res, 0, nums.size() -1);
        return res;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

