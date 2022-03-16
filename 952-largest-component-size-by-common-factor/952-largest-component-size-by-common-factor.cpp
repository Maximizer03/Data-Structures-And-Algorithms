class Solution {
private:
    vector<int>p,r;
public:
    void init(int n){
        p.resize(n+1);
        r.resize(n+1);
        for(int v=0;v<=n;v++){
            p[v]=v;
            r[v]=0;
        }
    }
    int find_set(int v){
        if(v==p[v]){
            return v;
        }
        return p[v]=find_set(p[v]);
    }
    void union_sets(int a, int b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(r[a]<r[b]){
                swap(a,b);
            }
            p[b]=a;
            if(r[a]==r[b]){
                r[a]++;
            }
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int mx=*max_element(begin(nums),end(nums));
        init(mx+1);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int j=2;j*j<=x;j++){
                if(x%j==0){
                    union_sets(x,j);
                    union_sets(x,x/j);
                }
            }
        }
        map<int,int>m;
        for(int i=0;i<n;i++){
            int s=find_set(nums[i]);
            m[s]++;
        }
        int ans=0;
        for(auto &x:m){
            ans=max(ans,x.second);
        }
        return ans;
    }
};