class MinStack {
public:
stack< long long>st;
 long long minEle;
    MinStack() {
        
    }
    
    void push(int val) {
       if(st.empty()){
        st.push(val);
        minEle=val;
       }else{
        if(val>=minEle)
          st.push(val);
        else{
            st.push(2ll*val-minEle);
            minEle=val;
        }
       }
    }
    
    void pop() {
            if(minEle<=st.top())
               st.pop();
            else{ 
            minEle=2ll*minEle-st.top();
            st.pop();
            }
    }
    
    int top() {
        if(st.top()>=minEle)
           return st.top();
        else
          return minEle;
    }
    
    int getMin() { 
       return minEle;    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */