class Solution {
public:
       ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1,st2;
        while(l1!=NULL){
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            st2.push(l2->val);
            l2=l2->next;
        }
       int sum=0;
       int carry=0;
       ListNode* ans=new ListNode();
       while(!st1.empty() || !st2.empty()){
        if(!st1.empty()){
            sum+=st1.top();
            st1.pop();
        }
        if(!st2.empty()){
            sum+=st2.top();
            st2.pop();
         }
         ans->val=sum%10;
         carry=sum/10;

         ListNode* newNode=new ListNode(carry);
         newNode->next=ans;
         ans=newNode;
         sum=carry;
       }   
       return carry==0?ans->next:ans;
    }
};