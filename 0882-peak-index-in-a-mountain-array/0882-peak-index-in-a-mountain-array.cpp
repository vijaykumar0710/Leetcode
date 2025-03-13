class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
         int n=arr.size();
        if(n==1) return 0;
       int l=0,r=n-1;
       while(l<=r){
        int mid=l+(r-l)/2;
        if(mid>0 && mid<n-1){
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                   return mid;

           else if(arr[mid-1]>arr[mid])
                 r=mid-1;

          else l=mid+1;
        }
        else if(mid==0){
            if(arr[0]>arr[1])
            return 0;
            else l=mid+1;
        }
        else if(mid==n-1){
            if(arr[n-1]>arr[n-2])
               return n-1;
               else r=mid-1;
        }
       }
       return -1;
    }
};