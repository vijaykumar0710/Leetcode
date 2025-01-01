class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
         if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode* result;
        if(a->val<b->val){
            result=a;
            result->next=merge(a->next,b);
        }else{
            result=b;
            result->next=merge(a,b->next);
        }
        return result;
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