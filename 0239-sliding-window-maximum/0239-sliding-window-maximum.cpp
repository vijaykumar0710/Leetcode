class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
         int n=arr.size();
        vector<int>res;
        map<int,int,greater<int>>q;
        int i=0,j=0;
        while(j<n){
             q[arr[j]]++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                res.push_back(q.begin()->first);
                q[arr[i]]--;
                if(q[arr[i]]==0)
                   q.erase(arr[i]);
                    i++;
                    j++;
               }
            }
         return res;
    }
};