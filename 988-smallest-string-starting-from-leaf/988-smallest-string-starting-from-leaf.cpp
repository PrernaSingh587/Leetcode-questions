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
        if(!root->left && !root->right) {
            st+=(root->val+'a');
            string g=st;
            reverse(g.begin(),g.end());
            if(ans=="") ans=g;
            else {
                if(ans>g) ans=g; 
            }
            return ;
        }
        st+=(root->val+'a');
        solve(root->left,ans,st);
        
        solve(root->right,ans,st);
    }
    string smallestFromLeaf(TreeNode* root) {
        string st="";
        solve(root,st,"");
        return st;
    }
};