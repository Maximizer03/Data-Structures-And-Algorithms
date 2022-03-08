#include"bits/stdc++.h"
using namespace std;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int>sum(n+1,0);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+ (s[i-1]-'0');
    }
    int mx=0;
    for(int len=2;len<=n;len+=2){
        for(int st=0;st<=n-len;st++){
            int end= st+len-1;
            int leftSum= sum[st+ len/2]- sum[st];
            int rightSum= sum[end+1]-sum[st+len/2];
            if(leftSum==rightSum){
                mx=max(mx,len);
            }
        }
    }
    cout<<mx<<endl;
    
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}