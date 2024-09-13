class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries){    
           vector<int>res;            
           for(auto &query:queries){
            int left=query[0];
            int right=query[1];
            int ans=arr[left];
            for(int i=left+1;i<=right;i++){
                ans=ans^arr[i];
            }
            res.push_back(ans);
        }
        return res;
    }
};