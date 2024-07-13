class SmallestInfiniteSet {
public:
int currSmallest;
priority_queue<int,vector<int>,greater<int>>pq;
unordered_set<int> st;

    SmallestInfiniteSet() {
        currSmallest=1;
    }
    
    int popSmallest() {
        int result;
        if(!pq.empty()){
        result=pq.top();
        pq.pop();
        st.erase(result);
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
         pq.push(num);
         st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */