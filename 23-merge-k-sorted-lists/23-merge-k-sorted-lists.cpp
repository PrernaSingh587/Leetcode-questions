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
#define pp pair<int,ListNode*> 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pp,vector<pp>,greater<pp>>q;
        for(ListNode *s : lists) {
            if(s)
            q.push({s->val,s});
        }
        ListNode *head=NULL,*dummy=new ListNode(0),*ptr=dummy;
        while(!q.empty()) {
            pp k = q.top(); q.pop();
            ListNode *m=k.second;
            if(m->next) {
                q.push({m->next->val,m->next});
            }
            m->next=NULL;
            ptr->next =m;
            ptr=ptr->next;
        }
        return dummy->next;
    }
};