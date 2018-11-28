/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> m;
        if (head == nullptr) return head;

        RandomListNode * curr = head;
        while (curr != nullptr) {
            m[curr] = new RandomListNode(curr->label);
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr) {
            if (curr->random) { 
                m[curr]->random = m[curr->random];
            }
            m[curr]->next = m[curr->next];
            curr = curr->next;
        }

        return m[head];
    }
};
