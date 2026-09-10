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
    int count;
    pair<int, int> fn(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        auto [left, leftno] = fn(root->left);
        auto [right, rightno] = fn(root->right);

        int total = left + right+root->val, nodes =1+ leftno + rightno;
        if (nodes != 0)
            if ((total / nodes) == root->val)
                count++;
        return {left + right + root->val, 1 + leftno + rightno};
    }
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        fn(root);
        return count;
    }
};