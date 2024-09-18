class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>vec;
        for(auto &num:nums){
         vec.push_back(to_string(num));
        }
        auto lambda=[&](auto &p2,auto &p1){
            return p2+p1>p1+p2;
        };
        sort(vec.begin(),vec.end(),lambda);
        if(vec[0]=="0"){
            return "0";
        }
        string res="";
        for(auto &ch:vec){
            res+=ch;
        }
        return res;
    }
};