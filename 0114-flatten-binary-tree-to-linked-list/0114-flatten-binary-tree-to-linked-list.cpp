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
    TreeNode* temp = NULL;
    void solve(TreeNode* &root){
        if(root == NULL) return;
        solve(root->right);
        solve(root->left);
        root->right = temp;
        root->left = NULL;
        temp = root;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};