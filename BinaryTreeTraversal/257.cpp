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
    void dfs(TreeNode* node, vector<string> &result, string path_so_far) {
        if (node == nullptr) return;

        if (!path_so_far.empty()) {
            path_so_far += "->";
        }

        path_so_far += to_string(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path_so_far);
        } 
        
        dfs(node->left, result, path_so_far);
        dfs(node->right, result, path_so_far);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path_so_far;
        dfs(root, result, path_so_far);

        return result;
    }
};