class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
       ListNode* temp=insertGreatestCommonDivisors(head->next);

       ListNode* gcdNode=new ListNode(__gcd(head->val,head->next->val));

       gcdNode->next=temp;
       head->next=gcdNode;

       return head;
    }
};