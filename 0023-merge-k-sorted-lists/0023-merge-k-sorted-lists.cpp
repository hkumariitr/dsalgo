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
        if(lists.empty()) return NULL;
        int n = lists.size();
        priority_queue <pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(int i =0;i<n;i++){
            if(lists[i]) pq.push({lists[i]->val,lists[i]});
        }
        
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;

        while(!pq.empty()){
            auto p = pq.top();
            temp->next = p.second;
            pq.pop();
            temp = temp->next;
            if(p.second->next) pq.push({p.second->next->val,p.second->next});

        }
        return dNode->next;
    }
};