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
    queue<TreeNode*>q;
    unordered_map<TreeNode*,TreeNode*>mp;
    void leaf(TreeNode *root,TreeNode *par ) {
        if(!root) return ;
        mp[root]=par;
        if(!root->left && !root->right) {
            
            q.push(root);
            return;
        }
        leaf(root->left,root);
        leaf(root->right,root);
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(!root) return {};
        leaf(root,NULL);
        vector<vector<int>>v;
        while(!q.empty()) {
            int s=q.size();
            vector<int>an;
            while(s--) {
                TreeNode *f=q.front(); q.pop();
                TreeNode*par=mp[f];
                 an.push_back(f->val);
                if(par==NULL) break;
                if(par->left==f) par->left=NULL; 
                if(par->right==f) par->right=NULL;
               
                if(!par->left && !par->right) q.push(par);
            }
            v.push_back(an);
        }
        return v;
    }
};