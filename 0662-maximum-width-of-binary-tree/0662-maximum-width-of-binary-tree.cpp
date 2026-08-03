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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        long long maxi = 0;
        q.push({0, root});
        if (root == NULL)
            return 0;
        while (!q.empty()) {
            long long n = q.size();
            long long minind = q.front().first;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().second;

                maxi = max(maxi, q.front().first - minind);
                long long index = q.front().first - minind;
                q.pop();
                if (node->left)
                    q.push({2 * index + 1, node->left});

                if (node->right)
                    q.push({2 * index + 2, node->right});
            }
        }
        return maxi+1;
    }
};