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
    int getIdx(int ele, vector<int>& in) {
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == ele)
                return i;
        }
        return -1;
    }

    TreeNode* ImplTree(vector<int>& pre, vector<int>& in, int sIdx, int eIdx,
                       int& pIdx) {
        if (pIdx >= pre.size())
            return NULL;
        if (sIdx > eIdx)
            return NULL;

        int ele = pre[pIdx];
        pIdx++;

        int idx = getIdx(ele, in);
        TreeNode* temp = new TreeNode(ele);

        temp->left = ImplTree(pre, in, sIdx, idx - 1, pIdx);
        temp->right = ImplTree(pre, in, idx + 1, eIdx, pIdx);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pIdx = 0;
        return ImplTree(preorder, inorder, 0, inorder.size()-1,pIdx );
    }
};