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
#define ll long long 
class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root,1});
        int maxx=1;
        while(!q.empty()) {
           int s=q.size();
             int mini=INT_MAX,maxi=INT_MIN,top=0,kk=q.front().second;
            while(top<s) {
                auto k=q.front(); q.pop();
                TreeNode*j = k.first;  int l=k.second-kk;
                if(top==0) mini=l;
                if(top==s-1) maxi=l;
                top++;
                //cout<<l<<" ";
                if(j->left) {
                    q.push({j->left,(ll)2*l+1});
                    
                } 
                if(j->right) {
                    q.push({j->right,(ll)2*l+2});
                    
                } 
            }
            maxx=max(maxx,maxi-mini+1);
        }
        return maxx;
    }
};