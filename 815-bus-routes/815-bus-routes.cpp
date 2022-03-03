class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        // bus no, route no
        unordered_map<int,vector<int>>m;
        for(int i=0;i<routes.size();i++){
            // i is the route number
            for(int j=0;j<routes[i].size();j++){
                // route[i][j] is the bus no j on the ith route
                int bus= routes[i][j];
                int route= i;
                m[bus].push_back(route);
            }
        }
        queue<pair<int,int>>q;
        set<int>vis;
        set<int>visRoute;
        vis.insert(S);
        // cur_stop,no of buses taken to reach the cur_stop
        q.push({S,0});
        while(!q.empty()){
            int cur_stop= q.front().first;
            int bus_cnt= q.front().second;
            q.pop();
            if(cur_stop==T){
                return bus_cnt;
            }
            vector<int>route= m[cur_stop];
            for(int i=0;i<route.size();i++){
                int route_no=route[i];
                if(visRoute.find(route_no)!=visRoute.end()){
                    continue;
                }
                visRoute.insert(route_no);
                for(auto &x: routes[route_no]){
                    if(vis.find(x)==vis.end()){
                        q.push({x,bus_cnt+1});
                        vis.insert(x);
                    }
                }
            }
        }
        return -1;
    }
};