class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // int n=0;
        // ListNode* len=head;
        // while(len){
        //     n++;
        //     len=len->next;
        // }
        // ListNode* temp=head;
        // if(n==1)return 0;
        // for(int i=0;i<n/2-1;i++){
        //     temp=temp->next;
        //             }
        // temp->next=temp->next->next;
        // return head;
        ListNode* slow=head;
        ListNode* fast=head;
        if(slow->next==NULL) return 0;
        while(fast->next->next&&fast->next->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};