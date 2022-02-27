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
    void p(TreeNode* root, int &l,int k,int &ans) {
        if(!root) return;
        p(root->left,l,k,ans);
        l++;
        if(k==l) ans=root->val;
        p(root->right,l,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0,l=0;
        p(root,l,k,ans);
        return ans;
    }
};