class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>>adj;
        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string>st;
        st.push("JFK");
        vector<string>ans;
        while(!st.empty()){
            string v= st.top();
            if(adj[v].size()==0){
                ans.push_back(v);
                st.pop();
            }
            else{
                auto u= *adj[v].begin();
                adj[v].erase(adj[v].find(u));
                st.push(u);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};