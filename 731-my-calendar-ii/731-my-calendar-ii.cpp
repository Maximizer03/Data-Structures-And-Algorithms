class MyCalendarTwo {
public:
    map<int,int>m;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int sum=0,k=0;
        for(auto &x:m){
            sum+=x.second;
            k=max(k,sum);
        }
        if(k<3){
            return true;
        }
        else{
            m[start]--;
            m[end]++;
            return false;
        }
    }
};
