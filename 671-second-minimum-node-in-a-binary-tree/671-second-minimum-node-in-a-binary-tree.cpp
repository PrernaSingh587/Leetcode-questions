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
    int findSecondMinimumValue(TreeNode* root) {
        int m1=-1,m2=-1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                TreeNode *k=q.front(); q.pop();
                if(k->left) q.push(k->left);
                if(k->right) q.push(k->right);
                if(m1==-1) m1=k->val;
                else if(m1==k->val) continue;
                else if( m2==-1) m2=k->val;
                else if(k->val<m1) m1=k->val;
                else if(k->val<m2) m2=k->val;
                
            }
        }
        return m2;
    }
};