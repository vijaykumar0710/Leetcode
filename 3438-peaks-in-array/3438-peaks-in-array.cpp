class Solution {
public:

int computePeak(int i,vector<int>&nums){
 int n=nums.size();
 if(i==0 || i==n-1)
   return 0;
 return (nums[i]>nums[i-1] && nums[i]>nums[i+1])?1:0;
}

void buildSegTree(int i,int l,int r,vector<int>&segTree,vector<int>&isPeak){
if(l==r){
    segTree[i]=isPeak[r];
    return;
}
int mid=l+(r-l)/2;
buildSegTree(2*i+1,l,mid,segTree,isPeak);
buildSegTree(2*i+2,mid+1,r,segTree,isPeak);
segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

void updateSegTree(int pos,int val,int i,int l,int r,vector<int>&segTree){
if(l==r){
    segTree[i]=val;
    return;
}
int mid=l+(r-l)/2;
if(pos<=mid){
    updateSegTree(pos,val,2*i+1,l,mid,segTree);
}else{
   updateSegTree(pos,val,2*i+2,mid+1,r,segTree); 
}
segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

int countPeak(int start, int end, int i, int l, int r, vector<int>& segTree) {
        if(end - start <= 1)
            return 0;
        int ql = start + 1;
        int qr = end - 1;
        if(l > qr || r < ql)
            return 0; 
        if(ql <= l && r <= qr)
            return segTree[i]; 
        int mid = l + (r - l) / 2;
        return countPeak(start, end, 2 * i + 1, l, mid, segTree) +
               countPeak(start, end, 2 * i + 2, mid + 1, r, segTree);
    }

  vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
     int n=nums.size();
     vector<int>isPeak(n,0);
     for(int i=0;i<n;i++){
     isPeak[i]=computePeak(i,nums);
    } 

     vector<int>segTree(4*n,0);
     buildSegTree(0,0,n-1,segTree,isPeak);
    
     vector<int>res;
     for(auto &query:queries){
       int type=query[0];
       if(type==2){
        int idx=query[1],val=query[2];
        nums[idx]=val;
        for(int j=idx-1;j<=idx+1;j++){
            if(j>0 && j<n){
                int newPeak=computePeak(j,nums);
                if(isPeak[j]!=newPeak){
                  isPeak[j]=newPeak;
                  updateSegTree(j,newPeak,0,0,n-1,segTree);
                }
              }
           }
         }else{
            int start=query[1],end=query[2];
            res.push_back(countPeak(start,end,0,0,n-1,segTree));
         }
       }
     return res;
   }
};