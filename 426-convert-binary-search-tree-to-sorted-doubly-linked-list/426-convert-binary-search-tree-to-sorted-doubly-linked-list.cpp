class Solution {
public:
    Node *head=NULL,*last;
    void p(Node *root, Node *&k) {
        if(!root) return;
        p(root->left,k);
            if(head==NULL) {
                head=root;
            }
        last=root;
           root->left=k;
          if(k) k->right=root;
        k=root;
        p(root->right,k);
    }
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        Node *k=NULL;
        p(root,k);
        head->left=last;
        last->right=head;
        return head;
    }
};