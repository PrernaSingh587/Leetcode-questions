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
    unordered_map<int,int>mp;
    void p(TreeNode* root, int &f, int k) {
        if(!root) return;
        p(root->left,f,k);
        if(mp.count(k-root->val)) f=1;
        mp[root->val]=1;
        p(root->right,f,k);
    }
    bool findTarget(TreeNode* root, int k) {
        int f=0;
        p(root,f,k);
        return f;
    }
};