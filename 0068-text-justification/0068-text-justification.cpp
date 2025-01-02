class Solution {
public:
int MAX_WIDTH;
string getFinalWord(int i, int j, int evenlyDistribute, int remainSpaces, vector<string>& words){
    string s;
    for(int k=i;k<j;k++){
        s+=words[k];
        if(k==j-1) continue;
        for(int space=1;space<=evenlyDistribute;space++){
            s+=" ";
        }
        if(remainSpaces>0){
            s+=" ";
            remainSpaces--;
        }
    }
    while(s.length()<MAX_WIDTH){
        s+=" ";
    }
    return s;
}
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>result;
        int n=words.size();
        MAX_WIDTH=maxWidth;
        int i=0;

        while(i<n){
            int letterCount=words[i].size();
            int j=i+1;
            int spaces=0;

            while(j<n && words[j].size()+1+letterCount+spaces<=maxWidth){
                letterCount+=words[j].size();
                spaces++;
                j++;
            }
            int totalSpaces     =maxWidth-letterCount;
            int evenlyDistribute=spaces==0?0:totalSpaces/spaces;
            int remainSpaces    =spaces==0?0:totalSpaces%spaces;

            if(j==n){// means we are on last line:left justification
                evenlyDistribute=1;
                remainSpaces=0;
            }
            result.push_back(getFinalWord(i,j,evenlyDistribute,remainSpaces,words));
            i=j;
        }
        return result;
    }
};