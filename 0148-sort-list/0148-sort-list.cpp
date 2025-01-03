class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        ListNode* current=head;
        while(current){ 
        pq.push(current->val);
        current=current->next;
        }
    
        ListNode* sorted=new ListNode(pq.top());
        pq.pop();
        ListNode* temp=sorted;
        while(!pq.empty()){
            temp->next=new ListNode(pq.top());
            pq.pop();
            temp=temp->next;
        }
        return sorted;
    }
};