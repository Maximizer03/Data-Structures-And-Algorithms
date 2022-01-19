class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            return a.first>b.first;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
        for(auto x:m){
            pair<int,int>p= {x.second,x.first};
            q.push(p);
            if(q.size()>k){
                q.pop();
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};