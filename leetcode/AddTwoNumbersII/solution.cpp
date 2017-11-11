#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int>  n1;
        std::stack<int>  n2;

        ListNode * curr = l1;
        while (curr) {
            n1.push(curr->val);
            curr = curr->next;
        }

        curr = l2;
        while (curr) {
            n2.push(curr->val);
            curr = curr->next;
        }

        std::stack<int> res;
        int carry = 0;
        while (!(n1.empty() && n2.empty())) {
            int l = 0, r = 0;
            if (!(n1.empty())) {
                l = n1.top();
                n1.pop();
            }
            
            if (!(n2.empty())) {
                r = n2.top();
                n2.pop();
            }

            res.push((l + r + carry) %10);
            carry = (l+r+carry) / 10;
        }

        if (carry) {
            res.push(carry);
        }

        ListNode * head;
        ListNode * last = NULL;

        while (!(res.empty())) {
            curr = new ListNode(res.top());
            res.pop();
            if (last == NULL) {
                head = curr;
            } else { 
                last->next = curr;
            }
            last = curr;
        }

        return head;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

