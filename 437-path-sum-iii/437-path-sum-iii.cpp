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
    int cnt=0;
    void p(TreeNode* root, int sum, long long int temp, unordered_map<long long int,long long int>mp ) {
        if(!root) return;
        int x=root->val;
        temp+=x;
        if(mp.count(temp-sum)) {
            cnt+=mp[temp-sum];
        }
        mp[temp]++;
        p(root->left,sum,temp,mp);
        p(root->right,sum,temp,mp);
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<long long int,long long int>mp;
        mp[0]=1;
        p(root,sum,0,mp);
        return cnt;
    }
};