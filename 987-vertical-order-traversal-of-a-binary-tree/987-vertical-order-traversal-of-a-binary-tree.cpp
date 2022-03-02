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
     vector<vector<int>>v;
    map<int,map<int,vector<int>>>mp;
    void solve(TreeNode*root,int x,int l) {
        if(!root) return ;
        mp[x][l].push_back(root->val);
        solve(root->left,x-1,l+1);
        solve(root->right,x+1,l+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        for(auto i=mp.begin();i!=mp.end();i++) {
            vector<int>k;
            for(auto j=i->second.begin();j!=(i->second.end());j++) {
                sort(j->second.begin(),j->second.end());
                for(int d : j->second)
                k.push_back(d);
            }
            v.push_back(k);
        }
        return v;
    }
};