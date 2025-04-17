class Solution {
public:
void computeLPS(string &pattern,vector<int>&LPS){
    int n=pattern.size();
    LPS[0]=0;
    int len=0;
    int i=1;
    while(i<n){
        if(pattern[i]==pattern[len]){
            len++;
            LPS[i]=len;
            i++;
        }
         else{
            if(len!=0){
                len=LPS[len-1];
            }else{
                LPS[i]=0;
                i++;
            }
         }  
     }
}

bool KMP(string &txt,string &pattern,vector<int>&bLPS){
    int n=txt.size();
    int m=pattern.size();
    int i=0,j=0;
    while(i<n){ 
   if(txt[i]==pattern[j]){
      i++,j++;
   }
   if(j==m){
    return true;
      }else if(i<n && pattern[j]!=txt[i]){
        if(j!=0){
            j=bLPS[j-1];
        }else{
            i++;
        }
      }
    }
    return false;
}
    int repeatedStringMatch(string a, string b) {
        int cnt=0;
        vector<int>bLPS(b.size());
        computeLPS(b,bLPS);
        if(KMP(a,b,bLPS))
            return 1;
        
        string st="";
        while(st.size()<1e4+1*b.size()){
            st+=a;
            cnt++;
            if(KMP(st, b, bLPS))
            return cnt;
        }
        
        // if(KMP(st, b, bLPS))
        //     return cnt;

        // st += a;
        // cnt++;

        // if(KMP(st, b, bLPS))
        //     return cnt;
        return -1;
    }
};