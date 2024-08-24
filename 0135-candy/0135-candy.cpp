class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int count=n;
        if(ratings[0]>ratings[1]) count++;
        if(ratings[n-1]>ratings[n-2]) count++;
        for(int i=1;i<n-1;i++){
            if(ratings[i]>ratings[i-1] || ratings[i]>ratings[i+1]) count++;
        }
        return count;
    }
};