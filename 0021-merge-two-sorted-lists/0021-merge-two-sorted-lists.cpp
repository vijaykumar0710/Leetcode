class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* t=dummy;
        while(t1!=NULL && t2!=NULL){
              if(t1->val<t2->val){
                t->next=t1;
                t=t1;
                t1=t1->next;
              }else{
                t->next=t2;
                t=t2;
                t2=t2->next;
              }
        }
        if(t1) t->next=t1;
        else t->next=t2;
        return dummy->next;
    }
};