class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();
        int maxlen=-1;
        //make substring of every possible length
        for(int len=1;len<=n;len++){
            unordered_map<string,int>substring;
            for(int i=0;i<=n-len;i++){
                string substr=s.substr(i,len);
                // check that substr is special or not
                if(substr==string(len,substr[0])){
                    substring[substr]++;
                }
            }
            for(auto &it:substring){
                if(it.second>=3){
                   maxlen=max(maxlen,len); 
                }
            }
        }
        return maxlen;
    }
};