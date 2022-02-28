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
    Node* lowestCommonAncestor(Node* p, Node * q) {
       queue<Node*>qt;
        unordered_set<Node*>st;
        qt.push(p);
        while(!qt.empty()) {
            Node *x=qt.front(); qt.pop();
            st.insert(x);
              if(x->parent) qt.push(x->parent);
        }
        qt.push(q);
        while(!qt.empty()) {
            Node *x=qt.front(); qt.pop();
            if(st.find(x)!=st.end()) return x;
            if(x->parent) qt.push(x->parent);
        }
        return NULL;
    }
};