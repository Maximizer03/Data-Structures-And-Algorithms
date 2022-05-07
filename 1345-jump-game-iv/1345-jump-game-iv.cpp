class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        int steps=0;
        set<int>seen;
        seen.insert(0);
        while(q.size()>0){
            int s=q.size();
            for(int i=0;i<s;i++){
                int v=q.front();
                q.pop();
                if(v==n-1){
                    return steps;
                }
                vector<int>pos;
                if(v){
                    pos.push_back(v-1);
                }
                pos.push_back(v+1);
                int e= arr[v];
                if(m[e].size()){
                    for(auto &x:m[e]){
                        pos.push_back(x);
                    }
                    m[e].clear();
                }
                for(int x:pos){
                    if(seen.find(x)==seen.end()){
                        q.push(x);
                        seen.insert(x);
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};