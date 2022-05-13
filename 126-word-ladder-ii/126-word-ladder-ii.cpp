class Solution {
public:
    string start;
    void dfs(string v, unordered_map<string, set<string>>&par, vector<string>cur,vector<vector<string>>&res){
        if(*par[v].begin()=="*"){
            res.push_back(cur);
            return;
        }
        for(auto &u:par[v]){
            cur.push_back(v);
            dfs(u,par,cur,res);
            cur.pop_back();
        }
    }
	vector<vector<string>> findLadders(string B, string E, vector<string>& words) {
		unordered_set<string>s;
		unordered_map<string, int>vis, dist;
		unordered_map<string, set<string>>par, g;
		for (string k : words) {
			s.insert(k);
		}
		s.insert(B);
		for (auto &x : s) {
			string cur = x;
			for (int i = 0; i < cur.size(); i++) {
				char org = cur[i];
				for (char ch = 'a'; ch <= 'z'; ch++) {
					if (ch == org) {
						continue;
					}
					cur[i] = ch;
					if (s.find(cur) != s.end()) {
						g[x].insert(cur);
					}
					cur[i] = org;
				}
			}
		}
		queue<string>q;
		par[B].insert("*");
		vis[B] = 1;
		q.push(B);
		dist[B] = 1;
        start=B; 
		while (!q.empty()) {
			string v = q.front();
			q.pop();
			for (auto &u : g[v]) {
				if (!vis.count(u)) {
					par[u].insert(v);
					vis[u] = 1;
					dist[u] = dist[v] + 1;
					q.push(u);
				}
				else if (dist[u] == dist[v] + 1) {
					par[u].insert(v);
				}
			}
		}
		vector<vector<string>>res;
        if(vis.count(E)==0){
            return res;
        }
        vector<string>cur;
        dfs(E,par,cur,res);
        for(int i=0;i<res.size();i++){
            vector<string>ans=res[i];
            reverse(begin(ans),end(ans));
            vector<string>fnl= {B};
            for(auto &y:ans){
                fnl.push_back(y);
            }
            res[i]=fnl;
        }
        return res;
	}
};