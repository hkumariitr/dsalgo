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
    TreeNode* dfs(TreeNode* node) {
        if (!node) return nullptr;
        TreeNode* leftTail = dfs(node->left);
        TreeNode* rightTail = dfs(node->right);
        if (node->left) {
            if (leftTail) {
                leftTail->right = node->right;
            }
            node->right = node->left;
            node->left = nullptr;
        }
        // Return the last node in the flattened tree
        return rightTail ? rightTail : (leftTail ? leftTail : node);
    }
    void flatten(TreeNode* root) {
        // Helper function to perform the flattening
        dfs(root);
    }
};