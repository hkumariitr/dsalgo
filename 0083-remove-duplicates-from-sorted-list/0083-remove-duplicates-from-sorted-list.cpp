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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head;

        while(temp){
            if(temp->next && temp->next->val == temp->val){
                ListNode* dupl = temp->next;
                while(dupl->next){
                    if (dupl->next-> val == dupl->val ) {
                        dupl = dupl->next;
                    }else{
                        break;
                    }
                }
                temp->next = dupl->next;
                temp = dupl->next;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};