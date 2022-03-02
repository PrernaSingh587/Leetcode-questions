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
    priority_queue<pair<double,int>>q;
    void solve(TreeNode*root, double t, int k) {
        if(!root) return;
        solve(root->left,t,k);
        q.push({abs((double)t-root->val),root->val});
        if(q.size()>k) q.pop();
        solve(root->right,t,k);
    }
    vector<int> closestKValues(TreeNode* root, double t, int k) {
        if(!root) return {};
        vector<int>v;
        solve(root,t,k);
        while(!q.empty()) {
            auto j=q.top(); q.pop();
            v.push_back(j.second);
        }
        return v;    
    }
};