class Solution 
{
public:
    string path = "";
    TreeNode* LCA(TreeNode* root,int a, int b)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(root->val == a || root->val == b)
        {
            return root;
        }
        TreeNode* left = LCA(root->left,a,b);
        TreeNode* right = LCA(root->right,a,b);
        if(left == nullptr)
        {
            return right;
        }
        else if(right == nullptr)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
    bool dfs(TreeNode* root,int target)
    {
        if(root==nullptr)
        {
            return false;
        }
        if(root->val==target)
        {
            return true;
        }
        if(dfs(root->left,target))
        {
            path.push_back('L');
            return true;
        }
        if(dfs(root->right,target))
        {
            path.push_back('R');
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        TreeNode* lca = LCA(root,startValue,destValue);
        dfs(lca,startValue);
        reverse(path.begin(),path.end());
        string startpath = path;
        for(auto &c : startpath){c = 'U';}
        path = "";
        dfs(lca,destValue);
        reverse(path.begin(),path.end());
        

        return startpath + path;
    }
};