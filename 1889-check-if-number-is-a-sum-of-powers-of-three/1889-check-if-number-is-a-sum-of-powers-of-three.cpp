class Solution {
public:
    bool checkPowersOfThree(int n) {
        int num=n;
        while(num){
            if(num%3==2) return false;
            num/=3;
        }
        return true;
    }
};