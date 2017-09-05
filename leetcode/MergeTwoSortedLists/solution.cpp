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
            swap(small, large);
        }

        ListNode * res = small;
        ListNode * cur = res;
        while (true) {
            if (!small) {
                cur->next = large;
                break;
            }
            if (!large) {
                cur->next = small;
                break;
            }

            if (small->val > large->val) {
                swap(small, large);
            }

            ListNode * next = small;
            small = small->next;
            cur->next = next;
            cur = cur->next;
        }
        return res;
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

