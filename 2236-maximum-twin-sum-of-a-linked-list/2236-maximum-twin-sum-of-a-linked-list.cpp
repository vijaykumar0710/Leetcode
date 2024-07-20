class Solution {
public:
    int pairSum(ListNode* head) {
      ListNode* slow=head;
      ListNode* fast=head;
      while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
      }    
    ListNode* mid=slow;

    ListNode* Prev=NULL;
    ListNode* Curr=mid;
    ListNode* Next=mid;

    while(Curr!=NULL){
        Next=Curr->next;
        Curr->next=Prev;
        Prev=Curr;
        Curr=Next;
    }
    int sum=0;
   while(Prev!=NULL){
    sum=max(sum,head->val+Prev->val);
    head=head->next;
     Prev=Prev->next;
      } 
      return sum;
    }
};