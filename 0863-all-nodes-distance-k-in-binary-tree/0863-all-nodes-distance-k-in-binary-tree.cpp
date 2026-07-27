/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent,
                    unordered_map<TreeNode*, bool>& vis) {
        if (root == NULL)
            return;

        vis[root] = false;
        if (root->left) {
            parent[root->left] = root;
            vis[root->left] = false;
            markparent(root->left, parent, vis);
        }
        if (root->right) {
            parent[root->right] = root;
            vis[root->right] = false;
            markparent(root->right, parent, vis);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> vis;
        markparent(root, parent, vis);

        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        while (!q.empty()) {
            int n = q.size();
            if (k == 0)
                break;

            k--;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (parent[node] && !vis[parent[node]]) {
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};