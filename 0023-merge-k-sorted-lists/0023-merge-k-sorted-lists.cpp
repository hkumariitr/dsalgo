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
        using pi = pair<int,ListNode*>;
        priority_queue<pi,vector<pi>,greater<pi>> pq;

        for(int i =0;i<n;i++){
            if(lists[i]) pq.push({lists[i]->val, lists[i]});
        }

        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;

        while(!pq.empty()){
            auto node = pq.top().second;
            temp->next = node;
            pq.pop();           
            temp = temp->next;
            if(node->next) pq.push({node->next->val,node->next});
        }
        return dNode->next;
    }
};