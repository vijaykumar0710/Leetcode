class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>last_occurence(26);
        for(int i=0;i<n;i++){  //O(n)
            last_occurence[s[i]-'a']=i;
        }
        vector<int>result;
        int start=0;
        int end=0;
       for(int i=0;i<n;i++){   //O(n)
         end=max(end,last_occurence[s[i]-'a']);
         if(i==end){
            result.push_back(end-start+1);
            start=end+1;
         }
       }
        return result;
    }
};
// t.tc=O(n)