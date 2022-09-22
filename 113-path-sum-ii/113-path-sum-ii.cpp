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
    void p(TreeNode* root, int sum, vector<int>temp) {
        if(root==NULL) {
            return ;
        }
        if(!root->left && !root->right && sum-root->val==0) {
            temp.push_back(root->val);
            v.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        p(root->left,sum-root->val,temp);
        p(root->right,sum-root->val,temp);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        p(root,sum,{});
        return v;
    }
};