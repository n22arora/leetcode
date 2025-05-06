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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        if (head->next == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            cout<<"Before: "<<slow->val<<" "<<fast->val<<endl;
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                cout<<"After: "<<slow->val<<" "<<fast->val<<endl;
                return true;
            }
        }

        return false;
    }
};