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
    int maxi=0;
    vector<int>solve(TreeNode* root) {
        if(!root) return {INT_MIN,INT_MIN,INT_MIN,1};
        vector<int>l=solve(root->left),r=solve(root->right);
        int x=root->val;
        if(l[3]==0 || r[3]==0) return {INT_MIN,INT_MIN,INT_MIN,0};
        cout<<x<<" ";
        if(l[2]==INT_MIN && r[2]==INT_MIN) {
            maxi=max(maxi,root->val);
            return {root->val,root->val,root->val,1};
        }
        if(l[2]!=INT_MIN && r[2]!=INT_MIN) {
            if(x>l[1] && x<r[0]) {
                maxi=max(maxi,l[2]+r[2]+x);
                return {l[0],r[1],l[2]+r[2]+x,1};
            } else {
                return {INT_MIN,INT_MIN,INT_MIN,0};
            }
        }
        if(l[2]==INT_MIN) {
            if(x<r[0]) {
                maxi=max(maxi,r[2]+x);
                return {x,r[1],r[2]+x,1};
            } else return {INT_MIN,INT_MIN,-1,0};
        }
        if(r[2]==INT_MIN) {
            if(x>l[1]) {
                maxi=max(maxi,l[2]+x);
                return {l[0],x,l[2]+x,1};
            } else return {INT_MIN,INT_MIN,-1,0};
        }
        return {};
        
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxi;
    }
};