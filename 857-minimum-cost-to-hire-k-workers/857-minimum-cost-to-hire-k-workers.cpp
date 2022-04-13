class Solution {
public:
    double mincostToHireWorkers(vector<int>& Q, vector<int>& W, int k) {
        int n=Q.size();
        double ans=1e9;
        vector<pair<int,int>>p;
        // (wage,quality)
        for(int i=0;i<n;i++){
            p.push_back({W[i],Q[i]});
        }
        sort(begin(p),end(p),[&](const pair<int,int>&a, const pair<int,int>&b){
            return a.first*b.second< b.first*a.second;
        });
        priority_queue<int>q;
        double sum=0;
        for(int i=0;i<k;i++){
            q.push(p[i].second);
            sum+=p[i].second;
        }
        double ratio= (double)(p[k-1].first)/(double)(p[k-1].second);
        ans= min(ans,ratio*sum);
       // cout << ans << endl;
        for(int i=k;i<n;i++){
           // cout<<ans<<endl;
            sum+=p[i].second;
            q.push(p[i].second);
            sum-=q.top();
            q.pop();
            
            double ratio= (double)(p[i].first)/(double)(p[i].second);
            //cout << ratio << " ";
            ans=min(ans,ratio*sum);
           // cout << ans << endl;
        }
        return ans;
        
        // return 0;
        
    }
};