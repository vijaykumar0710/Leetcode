class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>token1;
        vector<string>token2;
        stringstream s1(version1);
        string word1;
        stringstream s2(version2);
        string word2;
        while(getline(s1,word1,'.')){
            token1.push_back(word1);
        }
        while(getline(s2,word2,'.')){
            token2.push_back(word2);
        }
        int i=0;
        while(i<token1.size() || i<token2.size()){
            int a=(i>=token1.size())?0:stoi(token1[i]);
            int b=(i>=token2.size())?0:stoi(token2[i]);
            if(a>b){
                return 1;
                break;
            }
           else if(a<b){
                return -1;
                break;
            }
           else i++;
        }
        return 0;
    }
};