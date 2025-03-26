class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        // first calculate the cummulative sum row-wise
        for(int row=0;row<rows;row++){
            for(int col=1;col<cols;col++){
                matrix[row][col]+=matrix[row][col-1];
            }
        }
        //Now, you need to find the "No. of subarrays with sum k" in downward direction
        int res=0;
        for(int startCol=0;startCol<cols;startCol++){
            for(int currCol=startCol;currCol<cols;currCol++){
                //We need to find all sub matrices sum
    
                //Now comes the concept of "No. of subarrays with sum k"
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;
                //go downward row-wise
                for(int row=0;row<rows;row++){
                    sum+=matrix[row][currCol]-(startCol>0?matrix[row][startCol-1]:0);
                    if(mp.count(sum-target)){
                        res+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return res;
    }
};