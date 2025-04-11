class Solution {
public:
    int longestSubstring(string s, int k) {
      int n=s.size();
     if(n==0) return 0;
     unordered_map<char,int>freq;
     for(auto ch:s){
        freq[ch]++;
        }
        for(int i=0;i<n;i++){
            if(freq[s[i]]<k){
                int left=longestSubstring(s.substr(0,i),k);
                int right=longestSubstring(s.substr(i+1),k);
                 return max(left,right);
            }
        }
        return n; 
    }
};