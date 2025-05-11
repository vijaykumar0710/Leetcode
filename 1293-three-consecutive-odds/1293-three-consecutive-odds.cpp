class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int conseOdd=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2!=0){
                conseOdd++;
                 if(conseOdd==3) return true;
            } 
          if(arr[i]%2==0) conseOdd=0;
        }    
         return false;
    }
};