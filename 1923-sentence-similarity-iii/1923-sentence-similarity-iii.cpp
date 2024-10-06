class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
     if(sentence1.length()<sentence2.length()){
        swap(sentence1,sentence2);
     }
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
          int i=0,j=n1-1,k=0,l=n2-1;
          while(k<n2 && i<n1 && tokens1[i]==tokens2[k]){
                 i++;
                 k++;
          }
            while(l>=k && tokens1[j]==tokens2[l]){ 
                    l--;
                    j--;
                }
          return l<k;
      }
};