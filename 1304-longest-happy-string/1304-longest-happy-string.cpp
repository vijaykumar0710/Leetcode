class Solution {
public:
typedef pair<int,char> p;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p,vector<p>> pq;
       if(a>0){
        pq.push({a,'a'});
       }
       if(b>0){
        pq.push({b,'b'});
       }
       if(c>0){
        pq.push({c,'c'});
       }
        string ans="";
       while(!pq.empty()){
        int currCount=pq.top().first;
        char currChar=pq.top().second;
        pq.pop();

        if(ans.length()>=2 && ans[ans.length()-1]==currChar && ans[ans.length()-2]==currChar){
            if(pq.empty()){
                break;
            }
            int nextCount=pq.top().first;
            char nextChar=pq.top().second;
            pq.pop();

            ans.push_back(nextChar);
            nextCount--;
            if(nextCount>0){
                pq.push({nextCount,nextChar});
            }
         }else{
                currCount--;
                ans.push_back(currChar);
            }
            if(currCount>0){
                pq.push({currCount,currChar});
            }
       }
       return ans;
    }
};