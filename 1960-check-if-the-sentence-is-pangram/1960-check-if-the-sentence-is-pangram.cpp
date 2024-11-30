class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>counter(26,0);
        int n=sentence.size();
        for(int i=0;i<n;i++){
            counter[sentence[i]-'a']++;
        }
        for(auto &num:counter){
            if(num==0) return false;
        }
        return true;
    }
};