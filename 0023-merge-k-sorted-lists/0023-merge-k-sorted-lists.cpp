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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;
        int n = lists.size();
        if(n==0) return NULL;
        for(int i =0;i<n;i++){
            ListNode* head = lists[i];
            while(head){
                values.push_back(head->val);
                head = head->next;
            }
        }
        
        if (values.empty()) return NULL;

        sort(values.begin(),values.end());
        
        int val =values[0];

        ListNode* head = new ListNode(val);
        ListNode* temp = head;
        int siz = values.size();
        for(int i =1;i<siz;i++){
            temp->next = new ListNode(values[i]);
            temp = temp->next;
        }
        return head;
    }
};