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
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) {
            return;
        }
        // Copy the value of the next node into the current node
        node->val = node->next->val;
        // Save the next node in a temporary pointer
        // ListNode* temp = node->next;
        // Bypass the next node
        node->next = node->next->next;
        // Delete the temporary node
        // delete temp;
        
    }
};