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
    int solve(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans ) {
        if(!root) return -1;
        int l=solve(root->left,p,q,ans);
        int r=solve(root->right,p,q,ans);
        if(root ==p || root==q) {
            if(l==1 || r==1) {
                ans=root;
                return -1;
            }
            return 1;
        }
        if(l==-1 && r==-1) {
            return -1;
        }
        if(r==1 && l==1) {
            ans=root; return -1;
        }
        
        if(r==1) return 1;
        if(l==1) return 1;
        return -1;
    }  
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        TreeNode *ans=NULL;
        solve(root,p,q,ans);
        return ans;
    } 
};