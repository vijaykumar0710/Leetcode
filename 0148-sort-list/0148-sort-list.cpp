class Solution {
public:
ListNode* merge(ListNode* headA,ListNode* headB){
    ListNode* dummy=new ListNode(-1);
    ListNode* t=dummy,*t1=headA,*t2=headB;
    // ListNode* t1=headA;
    // ListNode* t2=headB;
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
ListNode* findMid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=findMid(head);
        ListNode* midnext=mid->next;

         mid->next=NULL;

        ListNode* l=sortList(head);
        ListNode* r=sortList(midnext);

        return merge(l,r);
    }
};