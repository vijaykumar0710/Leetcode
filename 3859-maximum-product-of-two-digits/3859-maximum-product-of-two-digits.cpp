class Solution {
public:
    int maxProduct(int n) {
        vector<int>vec;
        int m=n;
        while(m){
            vec.push_back(m%10);
            m/=10;
        }
        sort(vec.begin(),vec.end());
        int s=vec.size();
        return vec[s-1]*vec[s-2];
    }
};