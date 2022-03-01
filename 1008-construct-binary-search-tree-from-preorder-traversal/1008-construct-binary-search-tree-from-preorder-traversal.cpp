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
    TreeNode* solve(vector<int>& p,int st,int en) {
        if(st>en) return NULL;
        if(st==en) {
           return new TreeNode(p[st]);
        }
        int i=st;
        while(i<=en && p[st]>=p[i]) {
            i++;
        }
        TreeNode*root = new TreeNode(p[st]);
        
            TreeNode *l=solve(p,st+1,i-1);
            TreeNode *r=solve(p,i,en);
            root->left=l;
            root->right=r;
            return root;
      
        
       
    }
    TreeNode* bstFromPreorder(vector<int>& p) {
        return solve(p,0,p.size()-1);
    }
};