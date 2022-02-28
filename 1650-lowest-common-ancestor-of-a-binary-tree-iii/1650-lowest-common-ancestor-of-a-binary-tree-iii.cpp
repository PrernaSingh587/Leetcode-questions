/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    int find(Node* p, Node * q) {
        if(!p) return 0;
        if(p==q) return 1;
         int l=find(p->left,q);
        if(l==1) return 1;
        int r=find(p->right,q);
        return r;
    }
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
       if(find(p,q)) return p;
        if(find(q,p)) return q;
        return lowestCommonAncestor(p->parent,q->parent);
    }
};