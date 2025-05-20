class Solution {
public:
   ListNode* collisionPoint(ListNode *headA, ListNode *headB,int d){
    ListNode* temp=headB;
    while(d--){
        temp=temp->next;
    }
    ListNode* temp2=headA;
    while(temp!=NULL){
        if(temp==temp2) return temp;
        temp=temp->next;
        temp2=temp2->next;
    }
    return NULL;
   }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0,n2=0;
        ListNode* t1=headA;
        ListNode* t2=headB;
        while(t1!=NULL){
            n1++;
            t1=t1->next;
        }
         while(t2!=NULL){
            n2++;
            t2=t2->next;
        }
        if(n2>n1){
            return collisionPoint(headA,headB,n2-n1);
        }else{
             return collisionPoint(headB,headA,n1-n2);
        }
        return NULL;
    }
};