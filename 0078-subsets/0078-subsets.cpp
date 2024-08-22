class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums){
        int n=nums.size(); 
        int subset=1<<n;
        vector<vector<int>>res;
        for(int num=0;num<subset;num++){
            vector<int>vec;
            for(int i=0;i<n;i++){
                if((num&(1<<i))){    // check if the bit is set or not 
                    vec.push_back(nums[i]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};