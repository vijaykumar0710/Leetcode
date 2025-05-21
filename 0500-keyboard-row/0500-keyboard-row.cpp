class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char>st1,st2,st3;
        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";
        for(auto &ch:s1) st1.insert(ch);
        for(auto &ch:s2) st2.insert(ch);
        for(auto &ch:s3) st3.insert(ch);

        vector<string>res;
        for(auto &word:words){
            int cnt1=0,cnt2=0,cnt3=0;
              for(auto &c:word){ 
                char ch=tolower(c);
                if(st1.find(ch)!=st1.end()) cnt1++;
                else if(st2.find(ch)!=st2.end()) cnt2++;
                else cnt3++;
            }
             if((cnt1>0 && cnt2==0 && cnt3==0) || (cnt1==0 && cnt3==0 && cnt2>0) || (cnt2==0 && cnt3>0 && cnt1==0)){
             res.push_back(word);
           }
        }
         return res;   
    }
};