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
    typedef long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        // if(root == NULL) return -1;

        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        ll maxW = INT_MIN;

        while(!q.empty()){
            ll size = q.size();
            ll l = q.front().second;
            ll r = q.back().second;
            maxW = max(maxW, r-l+1);

            while(size--){
                TreeNode* temp = q.front().first;
                ll i = q.front().second;
                q.pop();

                if(temp->left){
                    q.push({temp->left, 2*i+1});
                }

                if(temp->right){
                    q.push({temp->right, 2*i+2});
                }
            }
        }
        return maxW;
    }
};