class Solution {
public:
    int maximum69Number (int num) {
        int placeValue=0;
        int placeValueSix=-1;
        
        int n=num;
        while(n){
            if(n%10==6){
                placeValueSix=placeValue;
            }
            n/=10;
            placeValue++;
        }
        if(placeValueSix==-1) return num;
        return num+3*pow(10,placeValueSix);
    }
};