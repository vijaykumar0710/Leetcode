class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
         int n=arr.size();
        int l=0,r=n-1;
        int first=-1,last=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==x){
                first=mid;
                r=mid-1;
            }
            else if(arr[mid]>x){
                r=mid-1;
            }else l=mid+1;
        }
         l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==x){
                last=mid;
                l=mid+1;
            }
            else if(arr[mid]>x){
                r=mid-1;
            }else l=mid+1;
        }
        return {first,last};
    }
};