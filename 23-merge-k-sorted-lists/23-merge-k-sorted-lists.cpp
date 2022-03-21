#define ln ListNode

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& ls) {
        int n=ls.size();
        ln *dummy=new ln(-1),*ptr=dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>q;
        for(int i=0;i<n;i++) {
            if(ls[i])q.push({ls[i]->val,ls[i]});
        }
        while(!q.empty()) {
            pair<int,ListNode*> k=q.top(); q.pop();
            ListNode* d=k.second;
            ListNode* s=d->next;
            ptr->next=d;
            ptr=ptr->next;
            ptr->next=NULL;
            if(s)
                q.push({s->val,s});
        }
        return dummy->next;
    }
};