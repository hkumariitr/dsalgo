class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
    MinStack() {
        
        st2.push(INT_MAX);
    }
    
    void push(int val) {
        st1.push(val);
        st2.push(min(st2.top(),val));
    }
    
    void pop() {
        st1.pop();
        st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
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