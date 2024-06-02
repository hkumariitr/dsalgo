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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res; // Base case
        string path = to_string(root->val);
        if(!root->left && !root->right){
            res.push_back(path);
            return res;
        }
        dfs(root->left, path, res);
        dfs(root->right, path, res);
        
        return res;
    }

    void dfs(TreeNode* node, string path, vector<string>& res) {
        if (!node) return;

        path += "->" + to_string(node->val);
        
        if (!node->left && !node->right) {
            res.push_back(path); // Found a leaf node, add the current path to the result
            return;
        }

        if (node->left) {
            dfs(node->left, path, res); // Explore left subtree
        }

        if (node->right) {
            dfs(node->right, path, res); // Explore right subtree
        }
    }
};