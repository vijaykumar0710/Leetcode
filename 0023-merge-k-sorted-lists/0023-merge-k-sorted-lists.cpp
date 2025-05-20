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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        ListNode* merged=merge(lists[0],lists[1]);
        for(auto i=2;i<lists.size();i++){
            merged=merge(merged,lists[i]);
        }
        return merged;
    }
};