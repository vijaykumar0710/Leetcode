class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* t=head;
        vector<int>v;
        while(t!=NULL){
            v.push_back(t->val);
            t=t->next;
        }
        sort(v.begin(),v.end());
        int i=0;
        t=head;
       while(t!=NULL){
        t->val=v[i];
        i++,t=t->next;
       }
       return head;
    }
};