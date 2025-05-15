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
    int result = INT_MIN;

    int maxSum(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftGain = max(0, maxSum(node->left));
        int rightGain = max(0, maxSum(node->right));

        result = max(result, node->val + leftGain + rightGain);

        return node->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return result;
    }
};