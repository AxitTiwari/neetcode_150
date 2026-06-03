class MinStack {
public:
    stack<int> s;
    stack<int> min_s;

    MinStack() {
    }
    
    void push(int val) {
        s.push(val);

        val = min(val, min_s.empty() ? val : min_s.top());
        min_s.push(val);
    }
    
    void pop() {
        s.pop();
        min_s.pop();
    }
    
    int top() {
        return s.empty() ? NULL : s.top();
    }
    
    int getMin() {
        return min_s.empty() ? NULL: min_s.top();
    }
};
