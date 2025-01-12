class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        for(int i=0;i<1;i++){ 
        temp=temp->next;
        }
        head->next=swapPairs(head->next->next);
        temp->next=head;
        return temp;  
    }
};