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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode *dummy = new ListNode(-1),*p1=dummy,*p2,*p3,*t;
        dummy->next=head;
        p2=head,p3=head->next;
        while(p2 && p3) {
            t=p3->next;
            p3->next=NULL;
            p2->next=t;
            p3->next=p2;
            p1->next=p3;
            p1=p2; p2=t; if(t) p3=t->next;
        }
        return dummy->next;
    }
};