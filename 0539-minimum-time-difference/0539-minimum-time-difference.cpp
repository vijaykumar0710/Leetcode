class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minu;
        for(auto &time:timePoints){
            int hourint=stoi(time.substr(0,2));
            int minint=stoi(time.substr(3,2));

           int minutes=hourint*60+minint;
            minu.push_back(minutes);
        }
        sort(begin(minu),end(minu));
        int mini=INT_MAX;
        int n=minu.size();
       for(int i=1;i<n;i++){
        mini=min(mini,abs(minu[i]-minu[i-1]));
       }
       return min(mini,24*60-minu[n-1]+minu[0]);
    }
};