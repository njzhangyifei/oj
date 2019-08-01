/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * res = nullptr;
        ListNode * head;

        int carry = 0;
        while (l1 != nullptr) {
            int r = l1->val;
            l1 = l1->next;
            if (l2 != nullptr) {
                r += l2->val;
                l2 = l2 ->next;
            }

            int n_carry = (r + carry) / 10;
            r     = (r + carry) % 10;
            carry = n_carry;

            if (res == nullptr) {
                res = new ListNode(r);
                head = res;
            } else {
                res->next = new ListNode(r);
                res = res->next;
            }
        }

        while (l2 != nullptr) {
            int r = l2->val;
            l2 = l2 ->next;
            if (l1 != nullptr) {
                r += l1->val;
                l1 = l1->next;
            }

            int n_carry = (r + carry) / 10;
            r     = (r + carry) % 10;
            carry = n_carry;

            if (res == nullptr) {
                res = new ListNode(r);
                head = res;
            } else {
                res->next = new ListNode(r);
                res = res->next;
            }
        }

        if (carry > 0) {
            if (res == nullptr) {
                res = new ListNode(carry);
            } else {
                res->next = new ListNode(carry);
            }
        }

        return head;
    }
};
