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
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = reverseLL(slow->next);
        ListNode* t1 = head;
        ListNode* t2 = head2;

        while(t2){

            if(t1->val != t2->val){
                reverseLL(head2);
                return false;
            }
            
            t1 = t1->next;
            t2 = t2->next;
        }

        reverseLL(head2);
        return true;
    } 
};