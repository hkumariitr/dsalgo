/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_track, TreeNode* target ){
//         queue<TreeNode*> queue;
//         queue.push(root);
//         while(!queue.empty()){
//             TreeNode* current = queue.front();
//             queue.pop();
//             if(current->left){
//                 parent_track[current->left] = current;
//                 queue.push(current->left);
//             }
//             if(current->right){
//                 parent_track[current->right] = current;
//                 queue.push(current->right);
//             }
//         }
//     }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         unordered_map<TreeNode*, TreeNode*> parent_track;
//         markParents(root, parent_track, target);
//         unordered_map<TreeNode*,bool> visited;
//         queue<TreeNode*> queue;
//         queue.push(target);
//         visited[target] = true;
//         int curr_level = 0;
//         while(!queue.empty()){
//             int size = queue.size();
//             if(curr_level++==k) break;
//             for(int i =0;i<queue.size();i++){
//                 TreeNode* current = queue.front();
//                 queue.pop();
//                 if(current->left && !visited[current->left]){
//                     queue.push(current->left);
//                     visited[current->left] = true;
//                 }
//                 if(current->right && !visited[current->right]){
//                     queue.push(current->right);
//                     visited[current->right] = true;
//                 }
//                 if(parent_track[current] && !visited[parent_track[current]]){
//                    visited[parent_track[current]] = true; 
//                 }
//             }
//         }
//         vector<int> result;
//         while(!queue.empty()){
//             TreeNode* current = queue.front();
//             queue.pop();
//             result.push_back(current->val);
//         }
//         return result;

//     }
// };

class Solution {
public:
    // Maps each node to its parent
    unordered_map<TreeNode*, TreeNode*> parentMap;

    // Keeps track of visited nodes
    unordered_set<int> visited;

    // Stores the results
    vector<int> result;

    // Function that returns all nodes at distance K from the target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Find and store all parents of nodes
        storeParents(root, nullptr);
      
        // Perform search to find all nodes at distance k
        depthFirstSearch(target, k);
      
        return result;
    }

    // Helper method to relate each node to its parent in the tree
    void storeParents(TreeNode* node, TreeNode* parent) {
        if (!node) return;

        parentMap[node] = parent;
      
        storeParents(node->left, node);
        storeParents(node->right, node);
    }

    // The DFS method that traverses the tree to find nodes at a distance k
    void depthFirstSearch(TreeNode* node, int k) {
        // If the node is null or already visited, stop the search
        if (!node || visited.count(node->val)) return;

        // Mark the current node as visited
        visited.insert(node->val);

        // If the desired distance is reached, add the node's value to the results
        if (k == 0) {
            result.push_back(node->val);
            return;
        }

        // Continue the search in left and right subtree
        depthFirstSearch(node->left, k - 1);
        depthFirstSearch(node->right, k - 1);

        // Also consider the parent node in the search
        depthFirstSearch(parentMap[node], k - 1);
    }
};