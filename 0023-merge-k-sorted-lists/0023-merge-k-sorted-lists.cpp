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
    ListNode* merge2Lists( ListNode* node1,  ListNode* node2){
        ListNode* t1 = node1;
        ListNode* t2 = node2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(t1 && t2){
            if(t1->val<t2->val){
                temp->next = t1;
                t1 = t1->next;
                temp = temp->next;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
                temp = temp->next;
            }
        }

        if(t1){
            temp->next = t1;
            t1 = t1->next;
            temp = temp->next;
        }

        if(t2){
            temp->next = t2;
            t2 = t2->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;

        ListNode* head = lists[0];
        int n = lists.size();
        for(int i =1;i<n;i++){
            head = merge2Lists(head, lists[i]);
        }
        return head;
    }
};