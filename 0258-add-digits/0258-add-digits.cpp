class Solution {
public:
     int sum=0;
     int CountofDigits(int num){
       int count=0;
       sum=0;
       while(num!=0){
        sum+=num%10;
        num/=10;
        count++;
       }
         return count;
     }
    int addDigits(int num) {
       while(CountofDigits(num)>1){
          num=sum;
       }
       return sum;
    }
};