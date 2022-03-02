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
    int maxi=0;
    vector<int>solve(TreeNode* root) {
        if(!root) return {INT_MAX,INT_MIN,0};
        vector<int>l=solve(root->left),r=solve(root->right);
        int x=root->val;
        if(l.size()==0 || r.size()==0 || x>=r[0] || x<=l[1]) return {};
        int sum=x+l[2]+r[2];
        maxi=max(maxi,sum);
        return {min(x,l[0]),max(x,r[1]),sum};
        
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxi;
    }
};