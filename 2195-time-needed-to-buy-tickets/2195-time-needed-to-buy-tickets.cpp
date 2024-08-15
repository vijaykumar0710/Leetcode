class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int sum=0;
         for(int i=0;i<n;i++){
          if(i<=k){
            sum+=min(tickets[i],tickets[k]);
            }else{
                if(tickets[i]>=tickets[k]){
                    sum+=(tickets[k]-1);
                }else{
                    sum+=min(tickets[i],tickets[k]);
                }
            }
         }
         return sum;
    }
};