class Solution {
public:
    bool checkOnesSegment(string s) {
       int n=s.size();
       vector<pair<int,int>>group;
       int cnt=1;
       for(int i=1;i<n;i++){
        if(s[i]=='1' && s[i]==s[i-1]){
          cnt++;
        }else{
            group.push_back({s[i-1],cnt});
            cnt=1;
         }
       } 
       group.push_back({s[n-1],cnt});
       for(int i=1;i<group.size();i++){
            if(group[i].first=='1')
                return false;
       }
       return true;
    }
};