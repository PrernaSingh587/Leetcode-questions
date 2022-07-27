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
    TreeNode*solve(TreeNode*root) {
        if(!root) return NULL;
        TreeNode *left = solve(root->left);
        TreeNode *right = solve(root->right);
        TreeNode *k = left;
        while(k && k->right) {
            k=k->right;
        }
        root->left=NULL;
        if(left)
        root->right=left;
        if(k) k->right=right;
        return root;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};