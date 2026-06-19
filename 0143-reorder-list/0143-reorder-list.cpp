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
    ListNode* reverseList(ListNode* root) {
        ListNode* prev = NULL;
        ListNode* temp = root;

        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        second = reverseList(second);
        slow->next = nullptr;
        ListNode* first = head;

        while (second != NULL) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
    }
};