class Solution {
public:
void solve(string s,int i,unordered_set<string>&st,int currCount,int &maxCount){
    if(currCount+(s.length()-i)<=maxCount){
        return;
    }
    if(i>=s.length()){
        maxCount=max(maxCount,currCount);
        return;
    }
    for(int j=i;j<s.length();j++){
        string sub=s.substr(i,j-i+1);
        if(st.find(sub)==st.end()){
            st.insert(sub);  //DO
            solve(s,j+1,st,currCount+1,maxCount);  //explore
            st.erase(sub);  //undo
        }
    }
}
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int maxCount=0;
        int currCount=0;
        int i=0;
        solve(s,i,st,currCount,maxCount);
        return maxCount;
    }
};