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
    void bfs(TreeNode*& root, vector<vector<int>>& arr) {
        if (root == NULL)
            return;
        queue<TreeNode*> qu;
        qu.push(root);

        while (!qu.empty()) {
            int size = qu.size();
            vector<int> ans;

            for (int i = 0; i < size; i++) {
                TreeNode* temp = qu.front();
                qu.pop();
                ans.push_back(temp->val);
                if (temp->left != NULL) {
                    qu.push(temp->left);
                }
                if (temp->right != NULL) {
                    qu.push(temp->right);
                }
            }
            arr.push_back(ans);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(root, ans);
        return ans;
    }
};