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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comparer = [](const ListNode * a, const ListNode * b) -> bool {
            return a->val >= b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comparer)> pq(comparer);

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) { 
                pq.push(lists[i]);
            }
        }


        ListNode * head = nullptr;
        ListNode * curr = head;
        while (!pq.empty()) {
            // take out 
            ListNode * smallest = pq.top();
            pq.pop();

            if (head == nullptr) {
                head = new ListNode(smallest->val);
                curr = head;
            } else {
                curr->next = new ListNode(smallest->val);
                curr = curr->next;
            }

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return head;
    }
};
