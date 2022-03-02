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
    int maxi=INT_MIN;
    int solve(TreeNode *root) {
        if(!root) return 0;
         maxi=max(maxi,root->val);
        if(!root->left && !root->right) { 
            return root->val;}
        int l=solve(root->left);
        int r=solve(root->right);
        maxi=max(maxi,l+root->val);
        maxi=max(maxi,r+root->val);
        maxi=max(maxi,l+r+root->val);
        return root->val+max(max(l,r),0);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};