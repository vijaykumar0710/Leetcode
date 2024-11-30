class Solution {
public:
bool allZero(vector<int>&counter){
    for(int &i:counter){
        if(i!=0) return false;
    }
    return true;
}
    vector<int> findAnagrams(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<int>result;
        vector<int>counter(26,0);
        for(int i=0;i<n;i++){
           char ch=p[i];
           counter[ch-'a']++;
        }
        int i=0,j=0;
        while(j<m){
            counter[s[j]-'a']--;
            if(j-i+1==n){
                if(allZero(counter)){
                result.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};