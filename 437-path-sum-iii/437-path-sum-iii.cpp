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
   
    void solve(TreeNode* root, int t, int &ans,int sum, unordered_map<int,int>mp) {
        if(!root) return;
        sum+=root->val;
        //cout<<root->val<<" "<<sum<<endl;
        if(mp.count(sum-t)) {
            ans+=mp[sum-t];
        }
        mp[sum]++;
        solve(root->left,t,ans,sum,mp);
        solve(root->right,t,ans,sum,mp);
    }
    int pathSum(TreeNode* root, int t) {
        int ans=0;
         unordered_map<int,int>mp;
       mp[0]=1;
        solve(root,t,ans,0,mp);
        return ans;
    }
};