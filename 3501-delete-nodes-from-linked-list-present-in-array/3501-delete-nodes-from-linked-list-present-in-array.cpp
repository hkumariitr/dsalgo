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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        set<int> st;
        
        for(int i =0;i<n;i++){
            st.insert(nums[i]);
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while(head){
            while(head && st.find(head->val)!=st.end()){
                head = head->next;
            };
            temp->next = head;
            temp = temp->next;
            if(head) head = head->next;
        }
        return dummy->next;
    }
};