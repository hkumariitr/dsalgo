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
    void dfs(TreeNode* root,vector<int> &ans){
        if(root == NULL){
            return;
        }
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }

    vector<int> iter(TreeNode* root){
        vector<int> ans;
        TreeNode* curr = root;
        stack<TreeNode*> st;
        while(curr || !st.empty()){
            while (curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            ans.push_back(curr->val);
            st.pop();
            curr = curr->right;
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        return iter(root);
        // dfs(root,ans);
        // return ans;
        
    }
};