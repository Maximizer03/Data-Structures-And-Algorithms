class Solution {
public:
    void dfs(int v, int p, vector<vector<int>>&g, int st, vector<int>&dp,vector<int>&vis){
        dp[v]=max(dp[v],st);
        vis[v]=1;
        for(auto u:g[v]){
            if(u!=p){
                dfs(u,v,g,st+1,dp,vis);
            }
        }
    }
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int>dp(n,0);
        vector<vector<int>>g(n);
        vector<int>in(n,0);
        for(int i=0;i<n;i++){
            if(i<n-1){
                if(r[i]>r[i+1]){
                    g[i+1].push_back(i);
                    in[i]++;
                }
            }
            if(i-1>=0){
                if(r[i]>r[i-1]){
                    g[i-1].push_back(i);
                    in[i]++;
                }
            }
        }
        vector<int>o;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            o.push_back(v);
            for(auto &u:g[v]){
                in[u]--;
                if(in[u]==0){
                    q.push(u);
                }
            }
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            int v= o[i];
            if(!vis[v]){
                dfs(v,-1,g,1,dp,vis);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=dp[i];
        }
        return sum;
    }
};