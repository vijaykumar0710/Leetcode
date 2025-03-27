class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size(),m=mana.size();
        vector<long long>t(n,0);
        for(int j=0;j<m;j++){
           long long lastEndTime=0;
           for(int i=0;i<n;i++){
            long long startTime=max(lastEndTime,t[i]);
            lastEndTime=t[i]=startTime+skill[i]*mana[j];
           }
           for(int i=n-1;i>=1;i--){
            t[i-1]=t[i]-skill[i]*mana[j];
           }
        }
        return t[n-1];
    }
};