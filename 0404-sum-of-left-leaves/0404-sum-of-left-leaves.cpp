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
    void dfs(TreeNode* root, int&sum,int &prev, bool isleft){
        if(!root) return ;

        dfs(root->left, sum,prev,true);

        if(!root->left && !root->right && isleft){
            cout<<"Adding sum for "<<root->val<<endl;
            sum += root->val;
        }
        if(root->right) prev = root->right->val;
        cout<<"prev is "<<prev<<endl;
        
        dfs(root->right, sum,prev,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum =0;
        int prev = INT_MAX;
        if(!root->left && !root->right){
            return 0;
        }
        dfs(root,sum,prev,true);

        return sum;
    }
};