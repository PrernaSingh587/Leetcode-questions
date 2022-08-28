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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root) return root;
        q.push(root);
        while(!q.empty()) {
            TreeNode *k=q.front();
            q.pop();
            TreeNode*temp=k->left;
            k->left=k->right;
            k->right=temp;
            if(k->left) q.push(k->left);
            if(k->right) q.push(k->right);
        }
        return root;
    }
};