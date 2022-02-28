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
    int x=0;
    int ans=INT_MIN;
    void solve(TreeNode*root,int &f) {
        if(!root) return;
        solve(root->left,f);
        if(x==0) {
            x=1;
            ans=root->val;
        } else {
            if(ans>=root->val) f=0;
        ans=root->val;
        }
        
        solve(root->right,f);
    }
    bool isValidBST(TreeNode* root) {
        int f=1;
        solve(root,f);
        return f;
    }
};