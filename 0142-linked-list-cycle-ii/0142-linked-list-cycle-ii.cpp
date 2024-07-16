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
    ListNode *getSlow(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast) return slow;

        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = getSlow(head);
        if(!slow) return NULL;
        while(slow != head){
            slow = slow->next;
            head = head->next;
        }
        return head;
    }
};