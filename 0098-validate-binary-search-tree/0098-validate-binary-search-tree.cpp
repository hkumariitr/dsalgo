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
    TreeNode* prev;
public:
    bool inorder(TreeNode* root){
        if(!root) return true;

        bool l = inorder(root->left);

        if(prev != NULL && root->val <=prev->val){
            return false;
        }
        prev = root;
        bool r = inorder(root->right);
        return l && r;
    }
//     bool check(TreeNode* root, long long lower, long long upper) {
//     if (root == NULL) {
//         return true;
//     }
//     if (root->val <= lower || root->val >= upper) {
//         return false;
//     }
//     return check(root->left, lower, root->val) && check(root->right, root->val, upper);
// }

bool isValidBST(TreeNode* root) {
    prev = NULL;
    return inorder(root);
}

};