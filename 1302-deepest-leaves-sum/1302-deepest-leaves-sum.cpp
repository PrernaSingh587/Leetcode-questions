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
    int height(TreeNode* root) {
        if(root) {
            int l=height(root->left);
            int r=height(root->right);
            if(l<r) return r+1;
            else return l+1;
        } return 0;
    }
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        int c=0;
        if(!root) return 0;
        while(!q.empty()) {
            int s=q.size();
            c++;
            while(s--) {
                TreeNode *p = q.front(); q.pop();
                int k=p->val;
                if(c==h) {
                    sum+=k;
                }
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
          //  c++;
        }
        return sum;
    }
};