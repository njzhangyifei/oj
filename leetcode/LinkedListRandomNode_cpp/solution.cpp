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
#include <random>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode * head;
        ListNode * selected; /** @param head The linked list's head.  Note that the head is guaranteed to be not null, so it contains at least one node. */ Solution(ListNode* head) { this->head = head;
        }

        /** Returns a random node's value. */
        int getRandom() {
            ListNode * curr = head;
            selected = head;
            size_t cnt = 0;
            std::random_device rd;
            std::mt19937 rng(rd());
            while (curr) {
                std::uniform_int_distribution<size_t> uni(0, cnt++);
                auto r = uni(rng);
                if (r == 0) {
                    selected = curr;
                }
                curr = curr->next;
            }
            return selected->val;
        }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

