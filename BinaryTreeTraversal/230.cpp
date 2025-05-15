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
    void dfs(TreeNode* node, priority_queue<int, vector<int>>& pq, int k) {
        if (node == nullptr) return;

        pq.push(node->val);

        if (pq.size() > k) pq.pop();

        dfs(node->left, pq, k);
        dfs(node->right, pq, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>> pq;

        dfs(root, pq, k);

        return pq.top();
    }
};