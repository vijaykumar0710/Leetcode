class Solution {
public:
void buildSegTree(int i,int l,int r,vector<int> &segTree,vector<int> &baskets){
if(l==r){
    segTree[i]=baskets[l];
    return;
 }
 int mid=l+(r-l)/2;
 buildSegTree(2*i+1,l,mid,segTree,baskets);
 buildSegTree(2*i+2,mid+1,r,segTree,baskets);
 segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
}

int query(int i,int l,int r,int fruit,vector<int>&segTree){
    if(segTree[i]<fruit) return -1;
    if(l==r) return l;
    int mid=l+(r-l)/2;
    if(segTree[2*i+1]>=fruit){
        return query(2*i+1,l,mid,fruit,segTree);
    }else{
        return query(2*i+2,mid+1,r,fruit,segTree);
    }
}

void update(int i,int l,int r,int pos,int val,vector<int>&segTree){
    if(l==r){
        segTree[i]=val;
        return;
    }
    int mid=l+(r-l)/2;
    if(pos<=mid){
        update(2*i+1,l,mid,pos,val,segTree);  
    }else{
        update(2*i+2,mid+1,r,pos,val,segTree);
    }
    segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
}

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>segTree(4*n,0);
        buildSegTree(0,0,n-1,segTree,baskets);
        int placed=0;
        for(auto fruit:fruits){
            int pos=query(0,0,n-1,fruit,segTree);
            if(pos!=-1){
                update(0,0,n-1,pos,0,segTree);
                placed++;
            }
        }
        return n-placed;
    }
};