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
    void dfs(TreeNode* root, int&sum, bool isleft){
        if(!root) return ;
        


        dfs(root->left, sum,true);  
        if(!root->left && !root->right && isleft){
            sum += root->val;
        }      
        dfs(root->right, sum,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum =0;
        if(!root->left && !root->right){
            return 0;
        }
        dfs(root,sum,false);

        return sum;
    }
};