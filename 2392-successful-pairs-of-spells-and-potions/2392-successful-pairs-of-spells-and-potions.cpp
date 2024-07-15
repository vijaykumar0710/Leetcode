class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       int m=spells.size();
       int n=potions.size();

       sort(begin(potions),end(potions));
       int maxPotionVal=potions[n-1];
        vector<int> answer;

        for(int i=0;i<m;i++){
            int spell=spells[i];
            long long minpotion=ceil((1.0*success)/spell);
             
            if(minpotion>maxPotionVal){
                answer.push_back(0);
                continue;
            }

            int index=lower_bound(begin(potions),end(potions),minpotion)-begin(potions);
            int count=n-index;
            answer.push_back(count);
        }
        return answer;
    }
};