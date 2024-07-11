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
    ListNode* getkNode(ListNode* temp, int k){
        k--;
        while(temp && k--){
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseLinkedList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            ListNode* knode = getkNode(temp,k);
            if(!knode){
                if(prev) prev->next = temp;
                break;
            }

            ListNode* nextNode = knode->next;
            knode->next = NULL;
            reverseLinkedList(temp);

            if(temp == head){
                head = knode;
            }else{
                prev->next = knode;
            }

            prev = temp;
            temp = nextNode;
        }
        return head;   
    }
};