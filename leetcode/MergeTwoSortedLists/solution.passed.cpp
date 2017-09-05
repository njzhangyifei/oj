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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * small = l1;
        ListNode * large = l2;
        if (!small && !large) {
            return NULL;
        }
        if (!small) {
            return large;
        } else if (!large) {
            return small;
        }

        if (small->val > large->val) {
            ListNode * tmp = small;
            small = large;
            large = tmp;
        }

        ListNode * res = small;
        ListNode * head = res;

        while (true) {
            if (!small) { // no more
                res->next = large;
                break;
            }

            if (!large) { // no more large
                res->next = small;
                break;
            }

            if (small->val > large->val) {
                ListNode * tmp = small;
                small = large;
                large = tmp;
            }


            ListNode * next = small;
            small = small->next; 
            res->next = next;
            res = res->next;
        }
        return head;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ListNode * l1 = new ListNode(2);
    ListNode * l2 = new ListNode(1);
    Solution s;
    s.mergeTwoLists(l1, l2);
    return 0;
}

