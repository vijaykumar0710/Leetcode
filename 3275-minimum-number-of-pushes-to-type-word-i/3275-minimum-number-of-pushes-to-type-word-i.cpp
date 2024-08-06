class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
      vector<int>vec(26,0);
      for(auto &ch:word){
        vec[ch-'a']++;
      }
      sort(vec.begin(), vec.end(),greater<int>());

      int size=vec.size();
      int totalPushes=0;
       for (int i = 0; i < size; i++) {
            int multiplier = (i / 8) + 1;  
            totalPushes += vec[i] * multiplier;
        }
        return totalPushes;
    }
};