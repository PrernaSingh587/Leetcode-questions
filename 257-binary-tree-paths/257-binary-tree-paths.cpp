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
    string help(int n) {
        int f=0;
        if(n<0) f=1;
        n=abs(n);
        string h;
        if(f==0)
         h=to_string(n);
        if(f==1) {
            h="-";
             h+=to_string(n);
        }
        return h;
    }
    vector<string>v;
    void solve(TreeNode *root, string h) {
        if(!root) return;
        h+=help(root->val);
        if(!root->left && !root->right) { 
            v.push_back(h);
            return;
        }
        h+="->";
        solve(root->left,h);
        solve(root->right,h);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root,"");
        return v;
    }
};