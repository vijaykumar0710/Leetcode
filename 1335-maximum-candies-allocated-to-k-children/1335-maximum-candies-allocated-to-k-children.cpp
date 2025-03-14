class Solution {
public:
int n;
bool isValid(vector<int>&arr,unsigned long k,unsigned long max){
      unsigned long children=0;
      for(int i=0;i<n;i++){
        children+=(arr[i]/max);
      }
      return children>=k;
  }
    int maximumCandies(vector<int>& candies, long long k) {
      n=candies.size();  
      unsigned long max_candies=0;
      unsigned long l=1,r=*max_element(begin(candies),end(candies));
      while(l<=r){
          unsigned long mid=l+(r-l)/2;
          if(isValid(candies,k,mid)){
              max_candies=mid;
              l=mid+1;
          }else{
              r=mid-1;
          }
      }
      return max_candies;
    }
};