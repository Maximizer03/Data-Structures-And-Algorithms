class Solution {
public:
    double binpow(double x, int n){
        long double ans=1.0;
        long long _n=abs(n);
        while(_n){
            if(_n%2==0){
                _n=_n/2; 
                x= x*x;
                
            }
            else{
               ans= ans*1.0*x;
                _n--;
            }
        }
        if(n<0){
            return 1.0/ans;
        }
        else{
            return ans;
        }
    }
    double myPow(double x, int n) {
        return binpow(x,n);
    }
};