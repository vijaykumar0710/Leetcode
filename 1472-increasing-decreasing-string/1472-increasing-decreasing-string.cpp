class Solution {
public:
    string sortString(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }

    int cnt=accumulate(freq.begin(),freq.end(),0);
    bool flag=true;
    
    string res="";
   while(cnt>0){ 
    string str=""; 
    for(int i=0;i<freq.size();i++){
      if(freq[i]>0){ 
        str+=(i+'a');
         freq[i]--;
         cnt--;
         }
       }
       if(!flag){
       reverse(str.begin(),str.end());
       }
      res+=str;
      flag=!flag;
       }
       return res;
    }
};