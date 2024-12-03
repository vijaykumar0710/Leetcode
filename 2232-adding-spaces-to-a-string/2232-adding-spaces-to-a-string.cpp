class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.size();
        int i=0,j=0;
        string newS="";
        for(int i=0;i<n;i++){
            if(j<spaces.size() && spaces[j]==i){
                newS+=' ';
                j++;
            }
             newS+=s[i];
        }
        return newS;
    }
};