class Solution {
public:
 void computelps(string pat,vector<int>&lps){
      int m=pat.size();
      int len=0;

      lps[0]=0;
      int i=1;
      while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
      }
    }
  
bool searchKMP(string pat,string txt){
    int n=txt.size();
    int m=pat.size();

    vector<int>lps(m,0);
    computelps(pat,lps);

     int i=0,j=0;

    while(i<n){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            return true;
        }else if(i<n && pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
    return false;
}
    vector<string> stringMatching(vector<string> &words) {
        int size = words.size();
        vector<string>result;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(i==j) continue;
                if(searchKMP(words[i],words[j])){
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};