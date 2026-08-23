/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (root == NULL)
            return 0;

        int l = solve(root->left, p, q, ans);
        int r = solve(root->right, p, q, ans);

        int self = (root == p || root == q) ? 1 : 0;

        int t = self + l + r;

        if (t == 2 && ans == NULL) {
            ans = root;
        }

        return t;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL ) return NULL;
        TreeNode* ans = NULL;
        int res = solve(root, p, q, ans);
        return ans;
    }
};