class Solution {
public:
string backtrack(string &num,int idx,unordered_set<string>&st){
        if(st.find(num)==st.end()){
            return num;
    }
    for(int i=idx;i<num.size();i++){
        if(num[i]=='0'){
            num[i]='1';
            if(st.find(num)==st.end()){
            return num;
    }
            backtrack(num,idx+1,st);
        }
         if(num[i]=='1'){
            num[i]='0';
            if(st.find(num)==st.end()){
            return num;
    }
            backtrack(num,idx+1,st);
        }
    }
    return "";
}
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
        for(auto &num:nums){
            st.insert(num);
        }
       return backtrack(nums[0],0,st);
    }
};