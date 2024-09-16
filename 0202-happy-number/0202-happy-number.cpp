class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>sta;
        while(n!=1){ 
        if(sta.count(n)) return false;
        sta.insert(n);
        int sum=0;
        while(n>0){
            int digit=n%10;
            sum+=digit*digit;
            n=n/10;
        }
        n=sum;
        }
        return true;
    }
};