class MyCalendar {
public:
    map<int,int>m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int sum=0,k=0;
        for(auto &x:m){
            sum+=x.second;
            k=max(k,sum);
        }
        if(k<2){
            return true;
        }
        else{
            m[start]--;
            m[end]++;
            return false;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */