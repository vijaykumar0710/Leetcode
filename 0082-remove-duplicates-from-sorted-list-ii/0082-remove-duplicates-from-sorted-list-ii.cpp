class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
       unordered_map<int,int>mp;
       ListNode *t=head;
       while(t){
          mp[t->val]++;
          t=t->next;
       }
       ListNode *dummy=new ListNode(-1);
       ListNode *j=dummy;
       ListNode *t1=head;
       while(t1){
          if(mp[t1->val]==1){
            j->next=t1;
            j=t1;
          }
          if(t1->next==NULL){
            j->next=NULL;
            return dummy->next;
          }
          t1=t1->next;
       }
       return dummy->next;
    }
};