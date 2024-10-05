class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();

        if(m>n) return false;

        vector<int>s1_freq(26,0);
        vector<int>s2_freq(26,0);

        for(char &ch:s1){
            s1_freq[ch-'a']++;
        }
        int i=0,j=0;
        while(j<n){
           s2_freq[s2[j]-'a']++;
           if(j-i+1>m){
            s2_freq[s2[i]-'a']--;
            i++;
           }
           if(s1_freq==s2_freq){
            return true;
           }
           j++;
        }
        return false;
    }
};