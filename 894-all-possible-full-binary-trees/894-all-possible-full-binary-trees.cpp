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
    #define solve allPossibleFBT
    unordered_map<int,vector<TreeNode*>>mp;
    vector<TreeNode*> allPossibleFBT(int n) {
      if(n%2==0) return {};
      if(n==1) {
          TreeNode*root = new TreeNode(0);
          return {root};
      }   
        if(mp.count(n)) return mp[n];
      int x=1,y=n-2;
      while(y>=1 && x<=n-2) {
         
         vector<TreeNode*>l,r;
         l=solve(x);
         r=solve(y);
         for(TreeNode* k : l) {
             for(TreeNode *m : r) {
                 TreeNode*root = new TreeNode(0);
             root->left=k;
                root->right=m;
                  mp[n].push_back(root);
             }
           
         }
          x+=2;
          y-=2;
       }
        return mp[n]; 
    }
};