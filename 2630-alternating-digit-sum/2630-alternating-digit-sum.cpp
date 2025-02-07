class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int>vec;
        while(n){
            vec.push_back(n%10);
            n/=10;
        }
        int m=vec.size();
        bool flag=true;
        int sum=0;
        for(int i=m-1;i>=0;i--){
           if(flag){
              sum+=vec[i];
              flag=false;
           }else{
            sum-=vec[i];
            flag=true;
           }
        }
        return sum;
    }
};