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
    TreeNode* ans=NULL;
    int solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return 0;
        int l=solve(root->left,p,q);
        int r=solve(root->right,p,q);
        if(l==0 && r==0) {
            if(root==p || root==q) return 1;
            else return 0;
        }
        if(l==0) {
            if(root==p || root==q) {
                ans=root;
                return 0;
            } return 1;
        }
        if(r==0) {
            if(root==p || root==q) {
                ans=root;
                return 0;
            } return 1;
        }
        ans=root;
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p ,q);
        return ans;
    }
};