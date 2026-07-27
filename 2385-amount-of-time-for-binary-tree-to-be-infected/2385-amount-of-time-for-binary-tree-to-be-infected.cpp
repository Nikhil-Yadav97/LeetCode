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
    TreeNode* find(TreeNode* root,int start)
    {
        if(root==NULL)
        return NULL;
        if(root->val==start)
        return root;
        TreeNode* left=find(root->left,start);
        TreeNode* right=find(root->right,start);
        if(left!=NULL)
        return left;
       
        return right;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> vis;
        markparent(root, parent, vis);
        TreeNode* target=find(root,start);
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int k=0;
        while (!q.empty()) {
            int n = q.size();
            

            k++;
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
        return k-1;
        
    }
};