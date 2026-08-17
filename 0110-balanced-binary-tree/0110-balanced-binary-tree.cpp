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
    int depthOfBt(TreeNode*& root) {
        if (root == NULL)
            return 0;
        int left = depthOfBt(root->left);
        int right = depthOfBt(root->right) ;
        return max(left, right) +1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        int left = depthOfBt(root->left);
        int right = depthOfBt(root->right);
        if (abs(left - right) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};