class Solution {
public:
 void backtrack(string &tiles,int idx,unordered_set<string>&st,int n,string &curr,vector<bool>&used){
    if(idx==n){
        st.insert(curr);
        return;
    } 
    for(int i=0;i<n;i++){
      if(used[i]==false){ 
      used[i]=true;
      backtrack(tiles,idx+1,st,n,curr,used);
      used[i]=false;
      curr+=tiles[i];
      used[i]=true;
      backtrack(tiles,idx+1,st,n,curr,used);
      used[i]=false;
      curr.pop_back();
      }
    }
 }
    int numTilePossibilities(string tiles) {
        int n=tiles.length();
        unordered_set<string>st;
        vector<bool>used(n,false);
        string curr;
        backtrack(tiles,0,st,n,curr,used);
        return st.size()-1;
    }
};