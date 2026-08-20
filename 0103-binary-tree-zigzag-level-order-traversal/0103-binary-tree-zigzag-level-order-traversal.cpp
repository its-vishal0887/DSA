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
    void solve(vector<vector<int>>&arr, TreeNode* &root){
        if(root == NULL) return;

        queue<TreeNode*>qu;
        qu.push(root);
        bool flag = true;

        while(!qu.empty()){
            int n = qu.size();
            vector<int>currNode;
            

            for(int i = 0; i<n; i++){
                TreeNode* temp = qu.front();
                qu.pop();
                currNode.push_back(temp->val);

                if(temp->left != NULL){
                    qu.push(temp->left);
                }

                if(temp->right != NULL){
                    qu.push(temp->right);
                }
            }
            if(!flag){
                reverse(currNode.begin(), currNode.end());
            }
            arr.push_back(currNode);
            flag = !flag;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>arr;
        solve(arr, root);
        return arr;
    }
};