/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode*root) {
        if (root == NULL)
            return 0;
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        int op1 = maxDepth(root->right) + maxDepth(root->left);
        int op2 = diameterOfBinaryTree(root->left);
        int op3 = diameterOfBinaryTree(root->right);
        return max(op1, max(op2, op3));
    }
};