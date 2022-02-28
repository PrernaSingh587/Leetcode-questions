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
    int ans=0;
    void solve(TreeNode*root, int k) {
        if(!root) {
            ans+=k;
            return;
        }
        k=k*10+root->val;
        if(root->left==NULL) {
            solve(root->right,k);
            return;
        } else if(root->right==NULL) {
             solve(root->left,k);
            return ;
        } 
         
        solve(root->left,k);
        solve(root->right,k);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        
        return ans;
    }
};