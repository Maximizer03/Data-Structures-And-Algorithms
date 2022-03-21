class Solution {
public:
    int uniquePaths(int n, int m) {
        if(n==1 || m==1){
            return 1;
        }
        if(n<m){
            swap(n,m);
        }
        n--;
        m--;
        long long ans=1;
        int j=1;
        for(int i=n+1;i<=n+m;i++){
            ans*=i;
            ans/=j;
            j++;
        }
        return (int)ans;
    }
};