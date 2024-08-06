class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
      unordered_map<char,int>mp;
      for (char c : word) {
            mp[c]++;
        }
      vector<int> vec;
      for(auto &i:mp){
        vec.push_back(i.second);
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