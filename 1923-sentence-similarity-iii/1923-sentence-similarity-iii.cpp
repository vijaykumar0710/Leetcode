class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
     if(sentence1.length()<sentence2.length()){
        swap(sentence1,sentence2);
     }
        deque<string>deq1;
        stringstream ss1(sentence1);
        string token1;
       while(getline(ss1,token1,' ')){
        deq1.push_back(token1);
       }

       deque<string>deq2;
       stringstream ss2(sentence2);
       string token2;
        while(getline(ss2,token2,' ')){
            deq2.push_back(token2);
        }

          while(!deq1.empty() && !deq2.empty() && deq1.front()==deq2.front()){
            deq1.pop_front();
            deq2.pop_front();
          }
          while(!deq1.empty() && !deq2.empty() && deq1.back()==deq2.back()){
            deq1.pop_back();
            deq2.pop_back();
          }
          return deq2.empty();
      }
};