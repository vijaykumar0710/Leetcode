class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<=n-3;i++){
            int conseOdd=0;
           if(arr[i]%2!=0)conseOdd++;
           if(arr[i+1]%2!=0)conseOdd++;
           if(arr[i+2]%2!=0)conseOdd++;
           if(conseOdd==3) return true;
        }    
         return false;
    }
};