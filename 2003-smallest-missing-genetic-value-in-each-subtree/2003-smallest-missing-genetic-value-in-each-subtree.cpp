class Solution {
public:
	void dfs(int v, vector<vector<int>>&g, vector<bool>&vis, vector<int>&gen, vector<int>&nums) {
		vis[v] = true;
		gen[nums[v]] = 1;
		for (auto &u : g[v]) {
			if (!vis[u]) {
				dfs(u, g, vis, gen, nums);
			}
		}
	}
	vector<int> smallestMissingValueSubtree(vector<int>& p, vector<int>& nums) {
		int n = nums.size();
		vector<int>ans(n, 1);
		bool pos = false;
		int mx = 0, st = 1, cur = 1;
		for (int i = 0; i < n; i++) {
			mx = max(mx, nums[i]);
			if (nums[i] == 1) {
				st = i;
			}
			if (nums[i] == 1) {
				pos = true;
			}
		}
		if (pos == false) {
			return ans;
		}
		vector<vector<int>>g(n);
		for (int i = 1; i < n; i++) {
			g[p[i]].push_back(i);
		}
		vector<int>gen(mx + 5, 0);
		vector<bool>vis(n + 3, 0);

		while (st != -1) {
			dfs(st, g, vis, gen, nums);
			while (gen[cur] != 0) {
				cur++;
			}
			ans[st] = cur;
			st = p[st];
		}
		return ans;
	}
};