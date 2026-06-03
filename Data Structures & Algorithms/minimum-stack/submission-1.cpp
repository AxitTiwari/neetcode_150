class MinStack {
public:
    stack<int> s;
    stack<int> min_s;

    MinStack() {
    }
    
    void push(int val) {
        s.push(val);

        if (min_s.empty()) {
            min_s.push(val);
            return;
        }

        if (min_s.top() < val) {
            min_s.push(min_s.top());
            return;
        }
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
