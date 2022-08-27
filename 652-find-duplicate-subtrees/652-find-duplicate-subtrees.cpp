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

    #define Node TreeNode
unordered_map<string,int>st;
vector<Node*>v;
string tostring(int k) {
    string h="";
    while(k) {
        h+=(k%10)+'0';
        k/=10;
    }
    reverse(h.begin(),h.end());
    return h;
}
string inorder(Node *root) {
    if(!root) return "n";
    string temp="";
    temp+=tostring(root->val);
    string l=inorder(root->left);
    string r=inorder(root->right);
    temp+='#';
    temp+=l;
    temp+='#';
    temp+=r;
    if(st.find(temp)!=st.end() && st[temp]==1) v.push_back(root);
    st[temp]++;
    return temp;
}
vector<Node*> printAllDups(Node* root)
{
    inorder(root);
    return v;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        return printAllDups(root);
    }
};