class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {

        vector<string>tokens1;
        stringstream ss1(sentence1);
        string token1;
       while(getline(ss1,token1,' ')){
        tokens1.push_back(token1);
       }

       vector<string>tokens2;
       stringstream ss2(sentence2);
       string token2;
        while(getline(ss2,token2,' ')){
            tokens2.push_back(token2);
        }

          int n1=tokens1.size();
          int n2=tokens2.size();
          int i=0,j=0;
          while(i<n1 && j<n2 && tokens1[i]==tokens2[j]){
                i++;
                j++; 
          }
          while(i<n1 && j<n2 && tokens1[n1-1]==tokens2[n2-1]){
            n1--;
            n2--;
          }
          return j==n2 || i==n1;
    }
};