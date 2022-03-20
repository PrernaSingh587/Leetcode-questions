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
    int maxi=INT_MIN;
   int solve(TreeNode *root) {
        if(!root) return INT_MIN;
        if(!root->left && !root->right) {
            maxi=max(maxi,root->val);
            return root->val;
        }
        int l=solve(root->left),r=solve(root->right);
         maxi=max(maxi,root->val);
       if(l==INT_MIN)
            maxi=max(maxi,root->val+r);
       if(r==INT_MIN)
            maxi=max(maxi,root->val+l);
       if(r!=INT_MIN && l!=INT_MIN)
        {maxi=max(maxi,root->val+l+r);
          maxi=max(maxi,root->val+r);
          maxi=max(maxi,root->val+l);
        }
      
      
      
        return root->val+max(0,max(r,l));
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};