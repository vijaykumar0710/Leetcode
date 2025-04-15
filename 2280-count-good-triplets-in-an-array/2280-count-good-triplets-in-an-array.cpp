class Solution {
public:
long long querySegTree(int queryStart,int queryEnd,int i,int l,int r,vector<long long>&segTree){
    if(r<queryStart || l>queryEnd) return 0;
    if(l>=queryStart && r<=queryEnd) return segTree[i];
    int mid=l+(r-l)/2;
    return querySegTree(queryStart,queryEnd,2*i+1,l,mid,segTree)+
           querySegTree(queryStart,queryEnd,2*i+2,mid+1,r,segTree);
} 

void updateSegTree(int i,int l,int r,int updateIdx,vector<long long>&segTree){
     if(l==r){
        segTree[i]=1;
        return;
     }
     int mid=l+(r-l)/2;
     if(updateIdx<=mid){
        updateSegTree(2*i+1,l,mid,updateIdx,segTree);
     }else{
        updateSegTree(2*i+2,mid+1,r,updateIdx,segTree);
     }
     segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }

        vector<long long> segTree(4*n);
        long long result=0;

       //update with first element,s mapped index from nums2
       updateSegTree(0,0,n-1,mp[nums1[0]],segTree);

       for(int i=1;i<n;i++){
        int idx=mp[nums1[i]];
        long long leftCommonCount=querySegTree(0,idx,0,0,n-1,segTree);
        long long leftNotCommonCount=i-leftCommonCount;
        long long elementsAfterIdxNums2=(n-1)-idx;
        long long rightCommonCount=elementsAfterIdxNums2-leftNotCommonCount;
        result+=(leftCommonCount*rightCommonCount);

        updateSegTree(0,0,n-1,idx,segTree);
       }
       return result;
    }
};