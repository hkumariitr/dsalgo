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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        while(list1){
            arr.push_back(list1->val);
            list1 = list1->next;
        }

        while(list2){
            arr.push_back(list2->val);
            list2 = list2->next;
        }

        if(arr.empty()) return NULL;

        sort(arr.begin(),arr.end());

        ListNode* head = new ListNode(arr[0]);
        ListNode* t = head;
        int n = arr.size();
        
        for(int i =1;i<n;i++){
            ListNode* temp = new ListNode(arr[i]);
            t->next = temp;
            t = t->next;
        }
        return head;
    }
};