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
    void solve(vector<vector<int>>& ans, TreeNode* root, int r, int sum,vector<int> arr) {
        if (root == NULL)
            return;
        sum += root->val;
        arr.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == r) {
                ans.push_back(arr);
                return;
            } else {
                return;
            }
        }
        solve(ans, root->left, r, sum, arr);
        solve(ans, root->right, r, sum, arr);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return {};
        vector<vector<int>> ans;
        vector<int> arr;
        solve(ans, root, targetSum, 0, {});
        return ans;
    }
};