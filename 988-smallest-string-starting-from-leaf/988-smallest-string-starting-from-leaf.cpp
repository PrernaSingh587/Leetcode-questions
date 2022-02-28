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
    string m="";
    int f=0;
    void solve(TreeNode *root, string h) {
        if(!root) return ;
        if(!root->left && !root->right) {
            h+=root->val+'a';
            string x=h;
            reverse(x.begin(),x.end());
            if(f==0) {
                f=1; m=x; return ;
            }
            if(m>x) m=x;
            return;
        }
        h+=root->val+'a';
        solve(root->left,h);
        solve(root->right,h);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return m;
    }
};