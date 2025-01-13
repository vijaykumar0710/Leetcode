class Solution {
public:
    int minimumLength(string s) {
        vector<int>vec(26,0);
        for(int i=0;i<s.size();i++){
            if(vec[s[i]-'a']==2){
                vec[s[i]-'a']=1;
            }else{
                vec[s[i]-'a']++;
            }
        }
        int sum=0;
        for(int i=0;i<26;i++){
            sum+=vec[i];
        }
        return sum;
    }
};