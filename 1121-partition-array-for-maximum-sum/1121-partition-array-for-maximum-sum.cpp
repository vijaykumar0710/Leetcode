class Solution {
public:
int t[501];
int f(int idx,vector<int>&arr,int k,int n){
    if(idx==n) return 0;
    int len=0;
    int maxi=INT_MIN;
    int MaxAns=INT_MIN;
    if(t[idx]!=-1) return t[idx];
    for(int j=idx;j<min (n,idx+k);j++){
        len++;
        maxi=max(maxi,arr[j]);
     int sum=len*maxi+f(j+1,arr,k,n);
     MaxAns=max(MaxAns,sum);
    }
    return t[idx]=MaxAns;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(t,-1,sizeof(t));
        return f(0,arr,k,n);
    }
};