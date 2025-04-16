class Solution {
public:
void solve(ListNode* head,vector<int>&vec){
    if(head==NULL) return;
    vec.push_back(head->val);
    solve(head->next,vec);
}
    int getDecimalValue(ListNode* head) {
        vector<int>vec;
        solve(head,vec);
        int res=0;
       int n= vec.size();
        for(int i=0;i<n;i++){
            res+=(vec[n-i-1]*pow(2,i));
        }
        return res;
    }
};