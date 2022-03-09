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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1),*pptr,*ptr=head;
        dummy->next= head;
        pptr=dummy;
        while(ptr) {
            int f=0;
            while(ptr && ptr->next && ptr->val==ptr->next->val) {
               f=1; ptr=ptr->next;
            }
            if(f)
            {pptr->next=ptr->next;
            }
            else 
           { pptr=ptr;
           }
            ptr=pptr->next;
            
        }
        return dummy->next;
    }
};