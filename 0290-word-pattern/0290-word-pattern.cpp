class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size();

       vector<string> tokens;
        unordered_set<string>st;
        stringstream ss(s);
        string token;
        int count=0;
        while(getline(ss,token,' ')){
            tokens.push_back(token);
            st.insert(token);
            count++;
        }
   
        unordered_set<char> st2;
         for(auto &it:pattern){
            st2.insert(it);
         }
         
       if(st.size()!=st2.size()) return false;
       
       if(count!=n) return false;
       
       unordered_map<char,string> mp;

        mp.insert({pattern[0],tokens[0]});

       for(int i=1;i<n;i++){
         if(mp.find(pattern[i])!=mp.end()){
            string word=mp[pattern[i]];
            if(word!=tokens[i]){
               return false;
            }
         }
         else{
            mp.insert({pattern[i],tokens[i]});
         }
       }      
       return true;
    }
};