class Solution {
public:
    int nthUglyNumber(int n) {  
        set<long long >st;
       st.insert(1);
       for(int i=1;i<n;i++){
        long long x=*st.begin();
        st.erase(*st.begin());
        st.insert(x*2);
        st.insert(x*3);
        st.insert(x*5);
       }
       return *st.begin();
    }
};