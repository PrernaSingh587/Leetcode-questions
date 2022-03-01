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
    unordered_set<TreeNode*>st;
    int num;
    TreeNode *ans;
    int solve(TreeNode* root,int num) {
        if(!root) return 0;
        int l=solve(root->left,num);
        int r=solve(root->right,num);
        if(l+r==num) {
            ans=root;
            return 0;
        }
        if(st.find(root)!=st.end()) {
             if(r+l+1==num) {
                    ans=root;
                    return 0;
                } else return r+1+l;
        } else return l+r;
            
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(nodes.size()==1) return nodes[0];
        for(TreeNode *p : nodes) {
            st.insert(p);
        }
        num=nodes.size();
        solve(root,num);
        return ans;
    }
};