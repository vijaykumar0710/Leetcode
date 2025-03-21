class MinStack {
public:
stack<int>st,minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || minSt.top()>=val)
          minSt.push(val);
    }
    
    void pop() {
        if(!minSt.empty() && minSt.top()==st.top())
           minSt.pop();
           st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() { 
       return minSt.top();    
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