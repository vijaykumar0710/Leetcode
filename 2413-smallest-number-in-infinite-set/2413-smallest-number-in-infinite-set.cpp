class SmallestInfiniteSet {
public:
int currSmallest;
set<int> st;

    SmallestInfiniteSet() {
        currSmallest=1;
    }
    
    int popSmallest() {
        int result;
        if(!st.empty()){
        result=*st.begin();
        st.erase(st.begin());
        }else{
            result=currSmallest;
            currSmallest+=1;
        }
        return result;
    }
    
    void addBack(int num) {
        if(num>=currSmallest || st.find(num)!=st.end()){ 
       return;
        }
         st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */