class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=s[i]-'a';
        }
        vector<int>diffArr(n+1,0);
        diffArr[0]=nums[0];
        for(int i=1;i<n;i++){
         diffArr[i]=nums[i]-nums[i-1];
        }

        for(auto query:shifts){
            int l=query[0];
            int r=query[1];
            int val=query[2];
            if(val==0){
                diffArr[l]-=1;
                if(r+1<n)
                   diffArr[r+1]+=1;
            }else{
                diffArr[l]+=1;
                if(r+1<n)
                   diffArr[r+1]-=1; 
            }
        }
         for(int i=1;i<n;i++){
            diffArr[i]+=diffArr[i-1];
         }
        
        for (int i = 0; i < n; i++) {
            int shift = ((diffArr[i]+26)%26+ 26) % 26; 
            s[i] = shift + 'a';
        }
        return s;
    }
};