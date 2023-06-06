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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,TreeNode*>mp;
        unordered_map<TreeNode*,int>mx;
        
        for(vector<int>v : desc) {
            int x=v[0],y=v[1],z=v[2];
            if(mp.count(x)==0) {
                TreeNode* node = new TreeNode(x);
                mp[x]=node;
                mx[node]=0;
            }
            if(z==1) {
                if(mp.count(y)==0) {
                    TreeNode* node = new TreeNode(y);
                    mp[y]=node;
                     mx[node]=0;
                }
                mp[x]->left=mp[y];
               
            } else {
                if(mp.count(y)==0) {
                    TreeNode* node = new TreeNode(y);
                    mp[y]=node;
                     mx[node]=0;
                }
                mp[x]->right=mp[y];
               
            }
             mx[mp[y]]++;
        }
        for(auto i=mx.begin();i!=mx.end();i++) {
            if(i->second==0) return i->first;
        }
        return NULL;
        
    }
};