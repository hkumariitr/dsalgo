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
    int dfs(TreeNode* root,bool &isBal){
        if(root == NULL){
            return 0;
        }
        int lh = dfs(root->left,isBal);
        if (lh == -1) {
            return -1; // Left subtree is unbalanced, propagate the imbalance up
        }
        int rh = dfs(root->right,isBal);
        if (rh == -1) {
            return -1; // Right subtree is unbalanced or height difference is greater than 1
        }
        if(abs(lh-rh)>1){
            isBal = false;
            return -1;

        }
        return 1 + max(lh,rh);

    }
    bool isBalanced(TreeNode* root) {
        bool isBal = true;
        dfs(root,isBal);
        return isBal;

    }
};