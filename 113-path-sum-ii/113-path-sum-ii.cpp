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
    vector<vector<int>>v;
    void solve(TreeNode* root, int t,vector<int>x,int sum) {
        if(!root) return ;
        sum+=root->val;
        x.push_back(root->val);
        if(!root->left && !root->right) {
            if(sum==t) v.push_back(x);
            return ;
        }
        solve(root->left,t,x,sum);
        solve(root->right,t,x,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        solve(root,t,{},0);
        return v;
    }
};