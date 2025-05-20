class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* t=head->next,*t1=head,*t2=head->next;
        while(t1->next && t2->next){
            t1->next=t2->next;
            t1=t2->next;
            t2->next=t1->next;
            t2=t1->next;
        }
        t1->next=t;
        return head;
    }
};