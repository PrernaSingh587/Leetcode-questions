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
    vector<int>solve(TreeNode* root) {
        if(!root) return {0,0};
        if(!root->left && !root->right) return {root->val,0};
        vector<int>l=solve(root->left),r=solve(root->right);
        int h=root->val+l[1]+r[1];
        int b=max(l[0]+r[1],max(l[1]+r[0],max(l[1]+r[1],l[0]+r[0])));
                  return {h,b};
    }
    int rob(TreeNode* root) {
        vector<int>v=solve(root);
        return max(v[0],v[1]);
    }
};