class Solution {
public:
void backtrack(string s,int idx,unordered_set<string>&st,int sum,int &result){
   if(idx>=s.length()){
    result=max(result,sum);
    return;
   }
   for(int i=idx;i<s.length();i++){
    string curr=s.substr(idx,i-idx+1);
    if(st.find(curr)==st.end()){
        st.insert(curr);
        backtrack(s,i+1,st,sum+1,result);
        st.erase(curr);
     }
   }
}
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int result=0,sum=0;
        int i=0;
        backtrack(s,i,st,sum,result);
        return result;
    }
};