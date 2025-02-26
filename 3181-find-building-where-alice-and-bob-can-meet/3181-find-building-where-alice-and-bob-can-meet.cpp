class Solution {
public:
void buildsegmentTree(int i,int l,int r,int segmentTree[],vector<int>&heights){
    if(l==r){
        segmentTree[i]=l;
        return;
    }
    int mid=l+(r-l)/2;
    buildsegmentTree(2*i+1,l,mid,segmentTree,heights);
    buildsegmentTree(2*i+2,mid+1,r,segmentTree,heights);

    segmentTree[i]=(heights[segmentTree[2*i+1]]>=heights[segmentTree[2*i+2]])?
                   segmentTree[2*i+1]:segmentTree[2*i+2];
}

int *construct(vector<int>&heights,int n){
    int *segmentTree=new int[4*n];
    buildsegmentTree(0,0,n-1,segmentTree,heights);
    return segmentTree;
}

int querySegmentTree(int start,int end,int i,int l,int r,int segmentTree[],vector<int>&heights){
    if(l>end || r<start){
        return -1; 
    }
    if(l>=start && r<=end){
        return segmentTree[i];
    }
    int mid=l+(r-l)/2;
    int leftIdx=querySegmentTree(start,end,2*i+1,l,mid,segmentTree,heights);
    int rightIdx=querySegmentTree(start,end,2*i+2,mid+1,r,segmentTree,heights);

    if(leftIdx==-1)
       return rightIdx;
    if(rightIdx==-1)
       return leftIdx;

    return (heights[leftIdx]>=heights[rightIdx])?leftIdx:rightIdx;
}

int RMIQ(int st[],vector<int>&heights,int n,int a,int b){
    return querySegmentTree(a,b,0,0,n-1,st,heights);
}
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
         int n=heights.size();
         int *segmentTree=construct(heights,n);

         vector<int>result;
         for(auto &query:queries){
            int min_idx=min(query[0],query[1]);
            int max_idx=max(query[0],query[1]);

            if(min_idx==max_idx || heights[max_idx]>heights[min_idx]){
                result.push_back(max_idx);
                continue;
            }
            int l=max_idx+1;
            int r=n-1;
            int result_idx=INT_MAX;
            while(l<=r){
                int mid=l+(r-l)/2;
                int idx=RMIQ(segmentTree,heights,n,l,mid);

                if(heights[idx]>max(heights[min_idx],heights[max_idx])){
                    r=mid-1;
                    result_idx=min(result_idx,idx);
                }else{
                    l=mid+1;
                }
            }
           if(result_idx==INT_MAX){
            result.push_back(-1);
           }else{
            result.push_back(result_idx);
           }
        }
        return result;
    }
};