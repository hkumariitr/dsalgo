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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        while(head && head->val == val){
            head = head->next;
        }
        ListNode* temp = head;
        ListNode* dNode = new ListNode(-1);
        dNode->next = head;
        ListNode* prev = dNode;
        ListNode* front = NULL;
        while(temp){
            front = temp->next;

            if(temp->val == val){
                prev->next = front;
                
            }else{
                prev = temp;
                
            }
            temp = front;
        }
        return dNode->next;
    }
};