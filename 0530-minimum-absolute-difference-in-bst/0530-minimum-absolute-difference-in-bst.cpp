/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, int& prev_val, int& min_diff) {
    if (!root) return;
    
    inorder(root->left, prev_val, min_diff);
    
    if (prev_val != INT_MAX) {
        min_diff = std::min(min_diff, root->val - prev_val);
    }
    
    prev_val = root->val;
    
    inorder(root->right, prev_val, min_diff);
}

int getMinimumDifference(TreeNode* root) {
    int prev_val = INT_MAX;
    int min_diff = INT_MAX;
    
    inorder(root, prev_val, min_diff);
    
    return min_diff;        
}
};