class MyCalendarThree {
public:
    map<int,int>m;
    MyCalendarThree() {   
    }  
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int k=0,sum=0;
        for(auto &x:m){
            sum+=x.second;
            k=max(k,sum);
        }
        return k;
    }
};