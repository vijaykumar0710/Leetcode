class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        sort(begin(items1),end(items1));
        sort(begin(items2),end(items2));
        int n=items1.size();
        int m=items2.size();
        int i=0,j=0;
        vector<vector<int>>res;
        while(i<n && j<m){
            int id1=items1[i][0];
            int val1=items1[i][1];
            int id2=items2[j][0];
            int val2=items2[j][1];
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
            res.push_back({items1[i][0],items1[i][1]});
                i++;
        }
        while(j<m){
            res.push_back({items2[j][0],items2[j][1]});
                j++;
        }
        return res;
    }
};