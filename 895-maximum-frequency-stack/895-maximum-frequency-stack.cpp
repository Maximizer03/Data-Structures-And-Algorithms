class FreqStack {
public:
    priority_queue<array<int,3>>q;
    int p=0;
    map<int,int>f;
    FreqStack() {
        
    }
    
    void push(int val) {
        f[val]++;
        p++;
        q.push({f[val],p,val});
    }
    
    int pop() {
        array<int,3>ans= q.top();
        q.pop();
        int val= ans[2];
        f[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */