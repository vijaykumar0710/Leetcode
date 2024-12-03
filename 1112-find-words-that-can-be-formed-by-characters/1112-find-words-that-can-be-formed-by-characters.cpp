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
            bool ok=true;
            for(auto &ch:word){ 
            if(temp[ch]>0){
                temp[ch]--;
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