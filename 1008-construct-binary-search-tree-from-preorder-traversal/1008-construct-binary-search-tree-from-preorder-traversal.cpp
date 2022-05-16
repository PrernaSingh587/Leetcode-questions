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
    TreeNode*solve(vector<int>v,int i,int j) {
     if(i>j) return NULL;
     if(i==j) return new TreeNode(v[i]);
     TreeNode* head=new TreeNode(v[i]);
     int x=i+1;
        
     while(x<=j && v[x]<v[i]) {x++;}
        if(x>(i+1)) x--;
     TreeNode*left=NULL,*right=NULL;
        //cout<<v[i]<<" "<<v[x]<<endl;
     if(v[i]>v[i+1]) 
     {left=solve(v,i+1,x);
     right=solve(v,x+1,j);} else {
         right=solve(v,x,j);
     }
     head->left=left;
     head->right=right;
    // cout<<head->val<<" "<<head->left->val<<" ";
     return head;
 }

    TreeNode* bstFromPreorder(vector<int> &v) {
         int h=v.size()-1;
    return solve(v,0,h);
    }
};