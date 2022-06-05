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
    void solve(TreeNode*root, string &ans,string st) {
        if(!root) return;
        char c = (root->val+'a');
            string g = c+st;
        if(!root->left && !root->right) {
            if(ans=="") ans=g;
            else {
                if(ans>g) ans=g; 
            }
            return ;
        }
       
        solve(root->left,ans,g);
        
        solve(root->right,ans,g);
    }
    string smallestFromLeaf(TreeNode* root) {
        string st="";
        solve(root,st,"");
        return st;
    }
};