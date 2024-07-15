class Solution {
public:
int lowerBound(int l,int r,vector<int>& potions,int minpotion){
    int possibleIndex=-1;
    int mid=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(potions[mid]>=minpotion){
            possibleIndex=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return possibleIndex;
}
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

            int index=lowerBound(0,n-1,potions,minpotion);
            int count=n-index;
            answer.push_back(count);
        }
        return answer;
    }
};