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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;
        ListNode* t1 =headA;
        ListNode* t2 = headB;
        while(t1 && t2){
            if(st.count(t1)) return t1;
            st.insert(t1);
            if(st.count(t2)) return t2;            
            st.insert(t2);
            t1 = t1->next;
            t2 = t2->next;
        }

        while(t1){
            if(st.count(t1)) return t1;
            st.insert(t1);
            t1 = t1->next;
        }

        while(t2){
            if(st.count(t2)) return t2;
            st.insert(t2);
            t2 = t2->next;            
        }

        return NULL;
    }
};