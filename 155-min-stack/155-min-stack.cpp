class MinStack {
public:
    vector<pair<int,int>>st;
    // (value,min)
    MinStack() {
        
    }
    
    void push(int val) {
        int cur= 2147483647;
        if(st.size()){
            cur= st.back().second;
        }
        int mn=min(cur,val);
        st.push_back({val,mn});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
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