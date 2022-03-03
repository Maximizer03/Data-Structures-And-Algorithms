class Solution {
public:
    struct cmp{
      bool operator()(const pair<int,int>&a, const pair<int,int>&b){
          return (a.first-a.second > b.first-b.second);
      }
    };
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        using pii= pair<int,int>;
        priority_queue<pii,vector<pii>,cmp>q;
      
        for(int i=0;i<n;i++){
            int a= costs[i][0];
            int b= costs[i][1];
            q.push({a,b});
        }
        int cnt=0,ans=0;
        while(!q.empty()){
            if(cnt<n/2){
                ans+=q.top().first;
            }
            else{
                ans+=q.top().second;
            }
            cnt++;
            q.pop();
        }
        return ans;
    }
};