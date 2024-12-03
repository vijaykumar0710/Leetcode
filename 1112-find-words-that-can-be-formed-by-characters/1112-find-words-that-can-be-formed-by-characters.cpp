class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp;
        for(auto &ch:chars){
            mp[ch]++;
        }
        int sum=0;
        for(auto &word:words){
            unordered_map<char,int> temp=mp;
            int n=word.size();
            int i=0;
            bool ok=true;
            while(i<n){ 
            if(temp[word[i]]>0){
                temp[word[i]]--;
                i++;
             }else{
                ok=false;
                break;
             }
           }
           if(ok==true) sum+=n;
        }
        return sum;
    }
};