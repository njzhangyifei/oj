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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode * slow = head;
        ListNode * fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * mid = slow->next;
        slow->next = nullptr;

        ListNode * cur = mid;
        ListNode * cur_next = nullptr;
        if (cur) {
            cur_next = cur->next;
            mid->next = nullptr;
        }
        while (cur_next) {
            ListNode* cur_nn = cur_next->next;
            cur_next->next = cur;
            cur = cur_next;
            cur_next = cur_nn;
        }
        
        ListNode * left = head;
        ListNode * right = cur;

        while (right) {
            ListNode * ln = left->next;
            ListNode * rn = right->next;

            left->next = right;

            if (!ln) break;

            right->next = ln;
            
            left = ln;
            right = rn;
        }
    }
};
