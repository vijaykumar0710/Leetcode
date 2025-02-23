class NumArray {
public:
int n;
vector<int>segTree;

void buildSegTree(int i,int l,int r,vector<int>&nums){
  if(l==r){
    segTree[i]=nums[r];
    return;
  }
  int mid=l+(r-l)/2;
  buildSegTree(2*i+1,l,mid,nums);
  buildSegTree(2*i+2,mid+1,r,nums);
  segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

void updateSegTree(int index,int val,int i,int l,int r){
if(l==r){
    segTree[i]=val;
    return;
   }
   int mid=l+(r-l)/2;
   if(index<=mid){
    updateSegTree(index,val,2*i+1,l,mid);
   }else{
    updateSegTree(index,val,2*i+2,mid+1,r);
   }
   segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

int querySegTree(int left,int right,int i,int l,int r){
if(l>right || r<left) return 0;
if(l>=left && r<=right) return segTree[i];
int mid=l+(r-l)/2;
return querySegTree(left,right,2*i+1,l,mid)+querySegTree(left,right,2*i+2,mid+1,r);
}

    NumArray(vector<int>& nums) {
        n=nums.size();
        segTree.resize(4*n);
        buildSegTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updateSegTree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return querySegTree(left,right,0,0,n-1);
    }
};