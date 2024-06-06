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
    int widthOfBinaryTree(TreeNode* root) {
        int ans =INT_MIN;
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long mini = q.front().second;
            int first,last;
            for(int i =0;i<size;i++){
                long long idx = q.front().second-mini;
                TreeNode* curr = q.front().first;
                q.pop();
                if(i==0) first = idx;
                if(i==size-1) last = idx;
                if(curr->left) q.push({curr->left,2*idx+1});
                if(curr->right) q.push({curr->right,2*idx+2});
            }
            ans = max(ans,static_cast<int>(last-first+1));
        }
        return ans;
    }
};