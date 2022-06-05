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
        int l=solve(root->left),r=solve(root->right);
        int x=root->val;
        maxi=max(maxi,x);
        maxi=max(maxi,x+l+r);
        maxi=max(maxi,x+l);
        maxi=max(maxi,x+r);
        return max(x+l,max(x,x+r));
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};