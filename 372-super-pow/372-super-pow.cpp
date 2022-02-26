class Solution {
public:
    int mod=1337;
    int f(long long a, long long b){
        long long ans=1;
        while(b){
            if(b%2){
                ans=(ans%mod * a%mod )%mod;
                b--;
            }
            else{
                a=(a%mod * a%mod) %mod;
                b=b/2;
            }
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if(b.size()==0){
            return 1;
        }
        int ld= b.back();
        b.pop_back();
        int ans= f(superPow(a,b),10)%mod  *  f(a,ld)%mod;
        return ans;
    }
};