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
class BSTIterator {
public:
    TreeNode *root,*ptr;
    TreeNode * dummy=new TreeNode(-1);
    void convert(TreeNode *root,TreeNode* &x,TreeNode* &head) {
        if(!root) return;
        convert(root->left,x,head);
        if(x)
        x->right=root;
        root->left=x;
       // cout<<x->val<<" "<<root->val<<endl;
        if(!head) head=root;
        x=root;
        convert(root->right,x,head);
    }
    BSTIterator(TreeNode* r) {
        root=r;
        TreeNode* x=NULL,*head=NULL;
        convert(root,x,head);
        dummy->right=head;
        ptr=dummy;
        TreeNode* k=ptr;
       
    }
    
    int next() {
        int h=ptr->right->val;
        ptr=ptr->right;
        return h;
    }
    
    bool hasNext() {
        return ptr->right!=NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */