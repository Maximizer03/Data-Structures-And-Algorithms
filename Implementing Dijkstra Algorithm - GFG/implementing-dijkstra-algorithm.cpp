// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> g[], int src)
    {
		const int INF = INT_MAX;
		vector<int>dist(n, INF);
		dist[src] = 0;
		// element of pq of the form (distance,node)
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
		q.push({dist[src], src});
		while (!q.empty()) {
			int cur_node = q.top().second;
			q.pop();
			for (auto &x : g[cur_node]) {
				int next_node = x[0];
				int weight = x[1];
				if (dist[next_node] > dist[cur_node] + weight) {
					dist[next_node] = dist[cur_node] + weight;
					q.push({dist[next_node], next_node});
				}
			}
		}
		return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends