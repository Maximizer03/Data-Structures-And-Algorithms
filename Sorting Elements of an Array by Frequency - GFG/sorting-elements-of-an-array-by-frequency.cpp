#include"bits/stdc++.h"
using namespace std;

struct cmp{
    bool operator()(const pair<int,int>&a, const pair<int,int>&b){
        if(a.first>b.first){
            return false;
        }
        else if(a.first==b.first){
            if(a.second>b.second){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
};

void solve(){
    int n;
    cin>>n;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        m[t]++;
    }
    using pii= pair<int,int>;
    priority_queue<pii,vector<pii>,cmp>q;
    for(auto &x:m){
        int num= x.first;
        int cnt= x.second;
        q.push({cnt,num});
    }
    while(!q.empty()){
        int cnt= q.top().first;
        int num=q.top().second;
        q.pop();
        for(int i=0;i<cnt;i++){
            cout<<num<<" ";
        }
    }
    cout<<endl;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}