class CustomStack {
public:
    vector<int>arr, f;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }

    void push(int x) {
        if (arr.size() < n) {
            arr.push_back(x);
            f.push_back(0);
        }
    }

    int pop() {
        if (arr.size()) {
            int fp =  f.back();
            int cur = arr.back() + fp;
            arr.pop_back();
            f.pop_back();
            if (f.size()) {
                f.back() += fp;
            }
            return cur;
        }
        else {
            return -1;
        }
    }

    void increment(int k, int val) {
        if (arr.size()) {
            int x = arr.size();
            int i = min(k - 1, x - 1);
            f[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */