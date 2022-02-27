class Solution {
public:
    class cmp{
    public:
        bool operator ()(const pair<int,int>&a, const pair<int,int>&b){
          int da= a.second-a.first;
          int db= b.second- b.first;
          if(da>db){
              return false;
          }
          else{
              return true;
          }
        }
    };
    
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        using pii= pair<int,int>;
        int ans=INT_MIN;
        priority_queue<pii,vector<pii>,cmp>q;
        for(int j=0;j<points.size();j++){
            while(!q.empty() && points[j][0]-q.top().first>k){
                q.pop();
            }
            if(!q.empty()){
                int xi= q.top().first;
                int xj= points[j][0];
                int yi= q.top().second;
                int yj= points[j][1];
                ans=max(ans,yi-xi+yj+xj);
            }
            q.push({points[j][0],points[j][1]});
        }
        return ans;
    }
};