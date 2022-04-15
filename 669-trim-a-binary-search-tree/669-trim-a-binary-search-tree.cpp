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
    pair<int,TreeNode*> solve(TreeNode* root, int ll, int hh) {
        if(!root) return {-2,NULL};
        if(!root->left && !root->right) {
            if(root->val >=ll && root->val<=hh) return {1,root};
            return {-1,NULL};
        }
        pair<int,TreeNode*> l=solve(root->left,ll,hh);
        pair<int,TreeNode*> r=solve(root->right,ll,hh);
        root->left=l.second;
        root->right=r.second;
        if(l.first==1 && r.first==1) return {1,root};
        if(l.first==1 && (r.first<0)) {
            root->right=NULL;
            if(root->val >=ll && root->val<=hh) return {1,root};
            TreeNode *temp=root->left;
            root->left=NULL;
            root=temp;
            return {1,root};
        }
         if(r.first==1 &&(l.first<0)) {
            root->left=NULL;
            if(root->val >=ll && root->val<=hh) return {1,root};
            TreeNode *temp=root->right;
            root->right=NULL;
            root=temp;
            return {1,root};
        }
        if(r.first<0 && l.first<0) {
            if(root->val >=ll && root->val<=hh) return {1,root};
            return {-1,NULL};
        }
        return {-1,NULL};
    }
    TreeNode* trimBST(TreeNode* root, int l, int h) {
        pair<int,TreeNode*> hk=solve(root,l,h);
        if(hk.first==-1) return NULL;
        return hk.second;
    }
};