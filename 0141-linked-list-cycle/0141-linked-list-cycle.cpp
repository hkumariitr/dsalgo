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
        set<ListNode*> vis;
        ListNode* temp = head;
        while(temp){
            if(vis.find(temp)!=vis.end()){
                return true;
            }else{
                vis.insert(temp);
                temp = temp->next;
            }
        }
        return false;
    }
};