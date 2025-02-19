class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* slow=head;
        while(slow!=NULL){
            size++;
            slow=slow->next;
        }
        if(n==size){
             head=head->next;
             return head;
         }
        int m=size-n;
        ListNode* temp=head;
        for(int i=0;i<m-1;i++){
           temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};