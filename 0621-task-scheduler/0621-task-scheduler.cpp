class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26);
        for(auto &task:tasks){
            freq[task-'A']++;
        }

        priority_queue<int>pq;
        for(auto fre:freq){
            if(fre>0)pq.push(fre);
        }

        int ans=0;
        while(!pq.empty()){
            vector<int>temp; 
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                int fre=pq.top();
                fre--;
                pq.pop();
                temp.push_back(fre);
            }
            }
           for(auto &fre:temp){
            if(fre>0) pq.push(fre);
           }
           if(pq.empty()) ans+=temp.size();
           else ans+=(n+1);
        }
        return ans;
    }
};