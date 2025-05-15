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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left_prev = dummy;
        ListNode* curr = head;

        for (int i = 0 ; i < left - 1 ; i++) {
            left_prev = curr;
            curr = curr->next;
        }

        ListNode* prev = nullptr;

        for (int i = 0 ; i < right - left + 1 ; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        left_prev->next->next = curr;
        left_prev->next = prev; 

        return dummy->next;
    }
};