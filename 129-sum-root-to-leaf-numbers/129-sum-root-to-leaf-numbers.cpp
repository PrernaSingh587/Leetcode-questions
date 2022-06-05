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
    int sum=0;
    void solve(TreeNode *root, int k) {
        if(!root) return ;
        k=k*10+root->val;
        if(!root->left && !root->right) {
            sum+=k;
            return ;
        }
        solve(root->left,k);
        solve(root->right,k);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return sum;  
    }
};