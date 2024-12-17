class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit ) {
        unordered_map<char,int>mp;
        for(auto &ch:s){
            mp[ch]++;
        }
        priority_queue<pair<char,int>>pq;
        for(auto &ele:mp){
            auto [ch,freq]=ele;
            pq.push({ch,freq});
        }
        string repeatLimitedString   ="";
        while(!pq.empty()){
         auto [ch, count] = pq.top();
            pq.pop();

            int mini=min(count,repeatLimit);
            count-=mini;
            repeatLimitedString.append(mini,ch);

            if(count>0 && !pq.empty()){
                auto [nxtch, nxtcount] = pq.top();
                pq.pop();
                repeatLimitedString+=nxtch;
                if(nxtcount>1){
                    pq.push({nxtch,nxtcount-1});
                }
                pq.push({ch,count});
              }
            } 
        return repeatLimitedString;
     }
};