class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>sta;
        while(n!=1){ 
        if(sta.count(n)) return false;
        sta.insert(n);
        string st=to_string(n);
        int sum=0;
        for(int i=0;i<st.size();i++){
            int x=st[i]-'0';
            sum+=x*x;
        }
        n=sum;
        }
        return true;
    }
};