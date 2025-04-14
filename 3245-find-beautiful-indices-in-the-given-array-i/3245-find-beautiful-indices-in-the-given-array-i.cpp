class Solution {
public:
void computeLPS(string &pattern,int m,vector<int>&LPS){
    int len=0;
    LPS[0]=0;
    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
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
}

void computeKMP(string &txt,string &pattern,vector<int>&LPS,vector<int>&vec){
    int n=txt.size(),m=pattern.size();
    int i=0,j=0;
    while(i<n){
        if(txt[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            vec.push_back(i-m);
            j=LPS[j-1];
        }else if(i<n && pattern[j]!=txt[i]){
            if(j!=0){
                j=LPS[j-1];
            }else{
                i++;
            }
        }
    }
}
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int size=s.size();
        int asize=a.size();
        int bsize=b.size();

        vector<int>aLPS(asize),bLPS(bsize);
        computeLPS(a,asize,aLPS);
        computeLPS(b,bsize,bLPS);

        vector<int>aKMP,bKMP;
        computeKMP(s,a,aLPS,aKMP);
        computeKMP(s,b,bLPS,bKMP);

        vector<int>res;
        for(int i=0;i<aKMP.size();i++){
            int left=aKMP[i]-k;
            int right=aKMP[i]+k;

            auto it=lower_bound(bKMP.begin(),bKMP.end(),left);

            if(it!=bKMP.end() && *it<=right){
                res.push_back(aKMP[i]);
            }
        }
        return res;
    }
};