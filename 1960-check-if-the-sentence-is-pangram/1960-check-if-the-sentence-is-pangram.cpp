class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>counter(26,0);
        int n=sentence.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(counter[sentence[i]-'a']==0){ 
            counter[sentence[i]-'a']++;
            count++;
            }
        }
       return count==26;
    }
};