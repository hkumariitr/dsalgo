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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if (!root) return false; // Base case

        return dfs(root,0, targetSum);
        
    }

    bool dfs(TreeNode* node, int sum, int k) {
        if (!node) return false;

        sum += node->val;

        if (!node->left && !node->right) {
            return sum ==k;
        }
        
        return dfs(node->left, sum, k) ||  dfs(node->right, sum, k);
        
    }
};