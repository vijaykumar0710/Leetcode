class StockSpanner {
public:
    stack<int> st;
    stack<int> fq;
    StockSpanner() {}

    int next(int price) {
        if (st.empty()) {
            st.push(price);
            fq.push(1);
            return 1;
        } else if (st.top() > price) {
            st.push(price);
            fq.push(1);
            return 1;
        } else {
            int temp = 1;
            while (!st.empty() && st.top() <= price) {
                st.pop();
                temp += fq.top();
                fq.pop();
            }
            st.push(price);
            fq.push(temp);
            return temp;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */