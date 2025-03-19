class StockSpanner {
private:
    stack<pair<int, int>> st; // {price, span}
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        // Accumulate span for prices <= current price
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
