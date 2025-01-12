class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         if(head==NULL || k==1){
            return head;
        }

        ListNode* temp=head;
        int count=0;
        while(temp){ 
            count++;
         temp=temp->next;
        }
        if(count<k)return head;
         
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = head;
        for(int i=0;i<k && current;i++){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        if(next){
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
 };