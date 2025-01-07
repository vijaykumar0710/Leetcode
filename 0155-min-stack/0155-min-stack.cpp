class MinStack {
private:
    stack<int> mainStack;  // Main stack to store elements
    stack<int> minStack;   // Auxiliary stack to store the minimums

public:
    MinStack() {
        // No specific initialization needed since the STL stack starts empty
    }

    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};