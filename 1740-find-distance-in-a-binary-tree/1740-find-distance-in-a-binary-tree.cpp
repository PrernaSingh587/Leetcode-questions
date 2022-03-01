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
    int ans;
    int solve(TreeNode* root, int p, int q) {
        if(!root) return 0;
        int l=solve(root->left,p,q),
        r = solve(root->right,p,q);
        if(l==0 && r==0) {
            if(root->val==p || root->val==q) {
                return 1;
            } else return 0;
        }
        if(l==0) {
            if(root->val==p || root->val==q) {
                ans=r+l;
                return 0;
            } else return r+1+l;
        } 
        if(r==0) {
            if(root->val==p || root->val==q) {
                ans=r+l;
                return 0;
            } else return r+1+l;
        }
        ans=l+r;
        return 0;
        
    }
    int findDistance(TreeNode* root, int p, int q) {
        if(!root) return 0;
        if(p==q) return 0;
        solve(root,p,q);
        return ans;
    }
};