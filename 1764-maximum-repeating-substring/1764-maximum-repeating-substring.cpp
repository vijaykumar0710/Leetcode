class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n=sequence.size();
        int m=word.size();
        //making LPS
        vector<int>LPS(m);
        LPS[0]=0;
        int i=1;
        int len=0;
        while(i<m){
            if(word[i]==word[len]){
                len++;
                LPS[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=LPS[len-1];
                }else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
    // KMP code
     vector<int>vec;
      i=0;
     int j=0;
     while(i<n){
        if(sequence[i]==word[j]){
            i++,j++;
        }
        if(j==m){
            vec.push_back(i-j);
            j=LPS[j-1];
        }else if(i<n && sequence[i]!=word[j]){
            if(j!=0){
               j=LPS[j-1];
            }else{ 
                i++;
            }
        }
     }
     if(vec.size()==0) return 0;
     int cnt=1;
     int res=0;
     for(int i=1;i<vec.size();i++){
        if(vec[i]-vec[i-1]==m){
            cnt++;
        }else{
           res=max(res,cnt);
           cnt=1;
        }
     }
     res=max(res,cnt);
     return res;
    }
};