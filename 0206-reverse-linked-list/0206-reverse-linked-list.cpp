class Solution {
public:
    ListNode* reverseList(ListNode* head) {     
        //   ITERATIVE method   
        //   ListNode* prev=NULL;
        //   ListNode* curr=head;
        //   ListNode* Next=head;
        //   while(curr){
        //   Next=curr->next;
        //   curr->next=prev;
        //   prev=curr;
        //   curr=Next;
        //   }
        //   return prev;

        //  RECURSION method
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
};