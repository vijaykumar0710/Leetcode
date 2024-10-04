class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=skill[i];
        }
        if(n==2) return skill[0]*skill[1];
        sort(skill.begin(),skill.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n/2;i++){
            mp[skill[i]]++;
        }
        int team=n/2;
        int score=sum/team;
        if(sum%team!=0) return -1;
        long long chem=0;
        for(int i=n/2;i<n;i++){
            int khoj=score-skill[i];
            if(mp[khoj]>0){  
              chem+=skill[i]*khoj;
              mp[khoj]--;
               }else return -1;
        }
        return chem;
    }
};