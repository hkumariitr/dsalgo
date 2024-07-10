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
    int countLength(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    int getDecimalValue(ListNode* head) {
        int i = countLength(head);
        int p = i-1;
        ListNode* temp  = head;
        int ans = 0;
        while(temp && i--){
            if(temp->val == 1){
                ans+= pow(2,p);
            }
            temp = temp->next;
            p--;
        }
        return ans;

    }
};