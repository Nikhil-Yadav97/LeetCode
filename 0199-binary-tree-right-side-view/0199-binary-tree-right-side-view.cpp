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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mpp;
        queue<tuple<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            while (n--) {

                auto [node, axes] = q.front();
                q.pop();
                if (node->right)
                    q.push({node->right, axes + 1});
                if (node->left)
                    q.push({node->left, axes + 1});

                if (mpp.find(axes) == mpp.end())
                    mpp[axes] = node->val;
            }
        }
        for (auto it : mpp)
            ans.push_back(it.second);

        return ans;
    }
};