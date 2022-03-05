Node *solve(Node *root) {
    if(!root) return NULL;
    Node *r = new Node(root->val);
    for(int i=0;i<root->children.size();i++) {
        r->children.push_back(solve(root->children[i]));
    }
    return r;
}

class Solution {
public:
    Node* cloneTree(Node* root) {
        return solve(root);
    }
};