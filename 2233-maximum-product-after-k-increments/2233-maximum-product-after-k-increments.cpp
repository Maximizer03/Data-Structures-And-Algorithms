class Solution {
public:
	int maximumProduct(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>>q;
		for (auto &x : nums) {
			q.push(x);
		}
		while (k--) {
			int v = q.top();
			q.pop();
			v++;
			q.push(v);
		}
		long long p = 1, mod = 1e9 + 7;
		while (!q.empty()) {
			int v = q.top();
			p = (p % mod * v % mod) % mod;
			q.pop();
		}
		return (int)(p);
	}
};