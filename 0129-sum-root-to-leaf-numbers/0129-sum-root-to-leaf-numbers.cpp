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
    void solve(TreeNode* &root, vector<string>&st, string &str){
        if(root == NULL) return;
        str += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            st.push_back(str);
        }
        solve(root->left, st, str);
        solve(root->right, st, str);
        str.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        vector<string>st;
        string str = "";
        solve(root, st, str);

        int sum = 0;
        for(auto &x : st){
            sum += std::stoi(x);
        }
        return sum;
    }
};