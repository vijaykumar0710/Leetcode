class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        vector<vector<int>>res;
        while(i<n && j<m){
            int id1=nums1[i][0];
            int val1=nums1[i][1];
            int id2=nums2[j][0];
            int val2=nums2[j][1];
            if(id1==id2){
                res.push_back({id1,val1+val2});
                i++;
                j++;
            }else if(id1<id2){
                res.push_back({id1,val1});
                i++;
            }else{
                res.push_back({id2,val2});
                j++;
            }
        }
        while(i<n){
            res.push_back({nums1[i][0],nums1[i][1]});
                i++;
        }
        while(j<m){
            res.push_back({nums2[j][0],nums2[j][1]});
                j++;
        }
        return res;
    }
};