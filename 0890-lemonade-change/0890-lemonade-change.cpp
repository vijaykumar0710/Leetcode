class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int rs5=0;
        int rs10=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5) rs5++;
            else if(bills[i]==10){
            if(rs5>0){ 
                rs5--;
                rs10++;
            } else return false;
            }
            else if(bills[i]==20){
                 if(rs10>0 && rs5>0){
                   rs5--;
                   rs10--;  
                }
                else if(rs5>=3){
                    rs5-=3;
                }
                else return false;
            }
        }
        return true;
    }
};