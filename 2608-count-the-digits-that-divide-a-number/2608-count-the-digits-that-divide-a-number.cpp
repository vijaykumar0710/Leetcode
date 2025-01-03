class Solution {
public:
 int solve(int num,int number,int &cnt){
     int divider=num%10;
     if(number%divider==0) cnt++;
     if(num/10>0)solve(num/10,number,cnt);
     return cnt;
 } 
    int countDigits(int num) {
        int number=num;
        int cnt=0;
        return solve(num,number,cnt);
    }
};