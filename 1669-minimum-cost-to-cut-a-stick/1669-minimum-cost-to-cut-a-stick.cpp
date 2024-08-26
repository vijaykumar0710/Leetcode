class Solution {
public:
int t[102][102];
int f(int i,int j,vector<int>&cuts){
    if(i>j) return 0;
    int mini=INT_MAX;
    if(t[i][j]!=-1) return t[i][j];
    for(int ind=i;ind<=j;ind++){
        int cost=cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts)+f(ind+1,j,cuts);
        mini=min(mini,cost);
    }
    return t[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        int N=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        memset(t,-1,sizeof(t));
        return f(1,N,cuts);
    }
};