class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *t=head;
        ListNode *j=dummy;
        while(t){
            if(t->next && t->val==t->next->val){ 
            while(t->next!=NULL && t->val==t->next->val){
                t=t->next;
            }
           j->next=t->next;
          }else{
            j=j->next;
          }
          t=t->next;
        }
        return dummy->next;
    }
};