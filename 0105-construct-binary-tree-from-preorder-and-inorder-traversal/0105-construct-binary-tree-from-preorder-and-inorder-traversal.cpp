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
    map<int, int> mpp;
    TreeNode* fn(vector<int>& preorder, vector<int>& inorder, int pst, int pend,
                 int ist, int iend) {
        if (ist > iend || pst > pend)
            return NULL;

        TreeNode* node = new TreeNode(preorder[pst]);
        
        int value=preorder[pst];
        int ind = mpp[value];
        int leftsize = ind - ist;
        node->left = fn(preorder, inorder, pst+1, leftsize+pst, ist, ind - 1);
        node->right = fn(preorder, inorder,leftsize+pst+1, pend, ind + 1, pend);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        mpp.clear();
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }
        return fn(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};