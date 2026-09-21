/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        if (head == nullptr) return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* before = dummy;

        while (true) {
            ListNode* kth = before;

            for (int i = 0; i < k; i++) {
                kth = kth->next;
                
                if (kth == nullptr) {
                    return dummy->next;
                }
            }

            ListNode* after = kth->next;
            ListNode* curr = before->next;
            ListNode* prev = after;

            while (curr != after) {
                ListNode* next = curr->next;

                curr->next = prev;
                prev = curr;
                curr = next;
            }

            ListNode* oldStart = before->next;
            before->next = kth;

            before = oldStart;
        }
    }
};