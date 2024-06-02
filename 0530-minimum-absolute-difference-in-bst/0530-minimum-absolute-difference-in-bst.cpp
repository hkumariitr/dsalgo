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
     void dfs(TreeNode* root, int &prev, int &diff ){
        if(!root) return;

        dfs(root->left, prev, diff);

        if(prev != INT_MAX){
            diff = min(diff, root->val -prev);
        }

        prev = root->val;

        dfs(root->right, prev, diff);
    }
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;

        int prev = INT_MAX;

        dfs(root,prev,diff);

        return diff;

    }
};